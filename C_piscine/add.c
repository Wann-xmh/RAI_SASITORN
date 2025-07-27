#define MAX_LEN 10000

// ฟังก์ชันช่วย: แยก key:value และเพิ่ม entry ถ้ายังไม่มี
void parse_and_add_entry(char *line, t_dict *dict, int *size)
{
    char *sep = line;
    while (*sep && *sep != ':')
        sep++;

    if (*sep != ':')
        return;

    *sep = '\0';
    char *key = ft_strtrim(line);
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

// ฟังก์ชันหลัก
int load_dict(const char *filename, t_dict *dict, int *size)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return 0;

    char buffer[MAX_LEN];
    int bytes = read(fd, buffer, MAX_LEN - 1);
    buffer[bytes] = '\0';
    close(fd);

    *size = 0;
    char *line = buffer;
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n' || buffer[i + 1] == '\0') {
            if (buffer[i] != '\n')
                i++; // ให้รวมตัวสุดท้ายถ้าไม่มี \n

            buffer[i] = '\0';
            parse_and_add_entry(line, dict, size);
            line = buffer + i + 1;
        }
    }

    return 1;
}
