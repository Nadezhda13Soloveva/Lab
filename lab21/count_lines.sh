#!/bin/bash

# Функция для подсчета числа строк в файле
count_lines() {
    file="$1"
    lines=$(wc -l < "$file")
    echo "$lines"
}

# Функция для обхода директории и ее подкаталогов
traverse_directory() {
    directory="$1"
    total_lines=0

    # Проверяем, существует ли указанная директория
    if [ -d "$directory" ]; then
        # Используем команду find для выбора файлов *.h и *.cpp
        # Выполняем подсчет числа строк в каждом файле и выводим его
        while IFS= read -r file; do
            if [[ $file == *".h" ]] || [[ $file == *".cpp" ]]; then
                lines=$(count_lines "$file")
                echo "Файл: $file, Количество строк: $lines"
                total_lines=$((total_lines + lines))
            fi
        done < <(find "$directory" -type f)

        echo "-------------------"
        echo "Суммарное количество строк: $total_lines"
    else
        echo "Директория не существует"
        exit 1
    fi
}

# Получаем от пользователя имя директории
echo "Введите имя директории:"
read directory

# Вызываем функцию для обхода директории и подсчета числа строк в файлах
traverse_directory "$directory"