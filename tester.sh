#!/bin/bash

# Définir le répertoire contenant les fichiers .s
champion_dir="champion"

# Vérifier si les executables existent
if [ ! -e "bin/asm" ] || [ ! -e "asm" ]; then
    echo "asm or bin/asm not found"
    exit 1
fi

# Parcourir récursivement les fichiers .s dans le répertoire champion
find champion -type f -name "*.s" | while read -r file; do
    # Extraire le nom de fichier sans extension
    filename=$(basename -- "$file")
    filename_no_ext="${filename%.*}"

    # Exécuter le binaire de référence
    bin/asm "$file"
    # Vérifier si le fichier .cor généré par le binaire de référence existe
    if [ -e "$filename_no_ext.cor" ]; then
        # Renommer le fichier .cor généré par le binaire de référence
        mv "$filename_no_ext.cor" "$filename_no_ext"_ref.cor
    fi

    # Exécuter notre binaire
    ./asm "$file"

    # Vérifier si les deux fichiers .cor existent avant de les comparer
    if [ ! -e "$filename_no_ext.cor" ] && [ ! -e "$filename_no_ext"_ref.cor ]; then
        echo -e "\033[1;32m$filename_no_ext.cor: OK [File is incorrect]\033[0m"
        continue
    fi

    # Comparer les fichiers .cor générés
    if diff "$filename_no_ext.cor" "$filename_no_ext"_ref.cor &> /dev/null; then
        echo -e "\033[1;32m$filename_no_ext.cor: OK\033[0m"
    else
        echo -e "\033[1;31m$filename_no_ext.cor: Error\033[0m"
    fi

    # Supprimer les fichiers .cor générés
    rm -rf "$filename_no_ext.cor" "$filename_no_ext"_ref.cor
done
