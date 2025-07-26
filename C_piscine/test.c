#include <unistd.h>  // write, read, close
#include <fcntl.h>   // open
#include <stdlib.h>  // malloc, free

#define MAX_ENTRY 100
#define MAX_LEN   1024

typedef struct s_dict {
    char *key;
    char *value;
} t_dict;

size_t ft_strlen(char *s) {
    size_t len = 0;
    while (s && s[len])
        len++;
    return len;
}

int ft_strcmp(char *s1, char *s2) {
    while (*s1 && *s2 && *s1 == *s2)
        s1++, s2++;
    return (*s1 - *s2);
}

char *ft_strdup(char *s) {
    size_t len = ft_strlen(s);
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (size_t i = 0; i <= len; i++)
        dup[i] = s[i];
    return dup;
}

char *ft_strtrim(char *s) {
    while (*s == ' ' || *s == '\t')
        s++;
    size_t len = ft_strlen(s);
    while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\n'))
        len--;
    char *out = malloc(len + 1);
    if (!out)
        return NULL;
    for (size_t i = 0; i < len; i++)
        out[i] = s[i];
    out[len] = '\0';
    return out;
}

int key_exists(t_dict *dict, int size, char *key) {
    for (int i = 0; i < size; i++) {
        if (ft_strcmp(dict[i].key, key) == 0)
            return 1;
    }
    return 0;
}

int load_dict(const char *filename, t_dict *dict, int *size) {
    int fd = open(filename, O_RDONLY);//O_RDWR using for read and write
    if (fd < 0)//เนื่องจากถ้า open ไม่ผ่านจะ return -1
        return 0;

    char buffer[MAX_LEN];
    int bytes = read(fd, buffer, MAX_LEN - 1);
    buffer[bytes] = '\0';
    close(fd);

    int i = 0, start = 0;
    *size = 0;
    while (buffer[i]) {
        if (buffer[i] == '\n' || buffer[i+1] == '\0') {
            int end = (buffer[i] == '\n') ? i : i + 1;
            buffer[end] = '\0';

            char *sep = buffer + start;
            while (*sep && *sep != ':')
                sep++;

            if (*sep == ':') {
                *sep = '\0';
                char *key = ft_strtrim(buffer + start);
                char *value = ft_strtrim(sep + 1);

                if (!key_exists(dict, *size, key)) {
                    dict[*size].key = key;
                    dict[*size].value = value;
                    (*size)++;
                } else {
                    free(key);
                    free(value);
                }
            }

            start = end + 1;
        }
        i++;
    }

    return 1;
}

void add_entry(t_dict *dict, int *size, char *key_str, char *val_str) {
    char *key = ft_strtrim(key_str);
    char *value = ft_strtrim(val_str);
    if (!key_exists(dict, *size, key)) {
        dict[*size].key = key;
        dict[*size].value = value;
        (*size)++;
    } else {
        free(key);
        free(value);
    }
}

void write_str(int fd, char *s) {
    write(fd, s, ft_strlen(s));
}

void save_dict(const char *filename, t_dict *dict, int size) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return;

    for (int i = 0; i < size; i++) {
        write_str(fd, dict[i].key);
        write_str(fd, " : ");
        write_str(fd, dict[i].value);
        write_str(fd, "\n");
    }

    close(fd);
}

void free_dict(t_dict *dict, int size) {
    for (int i = 0; i < size; i++) {
        free(dict[i].key);
        free(dict[i].value);
    }
}

int main(void) {
    t_dict dict[MAX_ENTRY];
    int dict_size = 0;

    if (!load_dict("dictionary.txt", dict, &dict_size))
        return 1;

    add_entry(dict, &dict_size, "2", "two");       // will be skipped if exists
    add_entry(dict, &dict_size, "4", "four");     // will be skipped
    add_entry(dict, &dict_size, "42", "forty-two"); // new entry

    save_dict("dictionary.txt", dict, dict_size);
    free_dict(dict, dict_size);
    return 0;
}
