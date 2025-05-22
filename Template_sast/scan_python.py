patterns = ["strcpy", 'get', ] 


with open('./Vuln_code/1.c', 'r', encoding='utf-8') as file:
    for lines_num, line in enumerate(file, start=1):
        for pattern in patterns:
            if pattern in line:
                print(f"Line {lines_num}: {line.strip()}")
                break
        