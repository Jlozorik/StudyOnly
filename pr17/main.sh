#!/bin/bash

if [[ $# -ne 1 || ! -d "$1" ]]; then
    echo "Ошибка: аргумент должен быть каталогом" >&2
    exit 1
fi

src="$1/source"
res="$1/results"

if [[ ! -d "$src" ]]; then
    echo "Ошибка: нет каталога source" >&2
    exit 1
fi

shopt -s nullglob

for s_path in "$src"/*; do
    [[ ! -d "$s_path" ]] && continue

    files=("$s_path"/*)
    if [[ ${#files[@]} -ne 1 ]]; then
        echo "Ошибка: неверное количество файлов у $(basename "$s_path")"
        continue
    fi

    f="${files[0]}"
    if [[ $(file -b --mime-type "$f") != text/* ]]; then
        echo "Ошибка: файл не текстовый у $(basename "$s_path")"
        continue
    fi

    echo "Студент: $(basename "$s_path")"
    less "$f"

    while true; do
        read -r -p "Оценка (0-6): " g < /dev/tty
        [[ "$g" =~ ^[0-6]$ ]] && break
    done

    mkdir -p "$res/$g"
    mv "$s_path" "$res/$g/"
done