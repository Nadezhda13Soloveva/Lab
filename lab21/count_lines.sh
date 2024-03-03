#!/bin/bash

# подсчет числа строк в файле
count_lines() {
    file="$1"
    lines=$(wc -l < "$file")
    echo "$lines"
}

# обход директории и ее подкаталогов
traverse_directory() {
    directory="$1"
    total_lines=0

    # проверяем, существует ли указанная директория
    if [ -d "$directory" ]; then
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

echo "Введите имя директории ('?' для спецификации):"
read directory

# проверка вывода спецификации программы
if [[ "$directory" == "?" ]]; then
    echo "Спецификация программы:"
    echo "Программа подсчитывает количество строк в файлах '*.h' и '*.cpp' в указанной директории и ее подкаталогах."
    exit 0
fi

# Проверяем пустой ввод для параметра directory и устанавливаем стандартное значение
if [[ -z "$directory" ]]; then
    directory='Test1'
    echo "Вы не ввели директорию, поэтому было взято стандартное значение Test1"
fi


traverse_directory "$directory"