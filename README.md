### Ошибка при ассемблировании

Инициализация переменной значением несовместимого типа

> [!CAUTION]
> На MacOS `Inline assembly` команды по умолчанию проверяются на этапе компиляции в ассемблер (т. к. компилируется через `CLang`)
> > On targets that use the integrated assembler (such as most X86 targets), inline assembly is run through the integrated assembler instead of your system assembler
> [Источник](https://clang.llvm.org/compatibility.html#inline-asm)
> 
> Решения:
> - Компилировать файл `main.s` (ассемблер файл с ошибкой)
> - Поменять `Clang` на `GCC`

> [!NOTE]
> Можно проверить с помощью 
> ```
> gcc -S main.c // на предыдущих этапах не было ошибки?
> gcc -c main.c
> ```
> ИЛИ
> ```
> gcc -S main.s // на предыдущих этапах не было ошибки?
> gcc -c main.s
> ```

