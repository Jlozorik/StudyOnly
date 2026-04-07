#!/bin/bash

if [ "$#" -lt 2 ]; then
    echo "Ошибка: недостаточно аргументов." >&2
    exit 1
fi

DEST_DIR="$1"
shift

if [ -d "$DEST_DIR" ]; then
    echo "Ошибка: целевой каталог '$DEST_DIR' уже существует." >&2
    exit 1
fi

mkdir -p "$DEST_DIR" || exit 1

COUNTER=1

for FILE in "$@"; do
    if [ ! -f "$FILE" ]; then
        echo "Ошибка: неправильный путь или файл '$FILE' не существует. Пропуск." >&2
        continue
    fi

    mv "$FILE" "$DEST_DIR/video-${COUNTER}.mp4"
    ((COUNTER++))
done