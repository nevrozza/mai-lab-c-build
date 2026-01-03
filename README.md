### Ошибка при ассемблировании

Неверная Assemly команда (в `.s` файле)

> [!NOTE]
> Для компиляции сразу двух файлов, один из которых `.s`, был изменён [CMakeLists.txt](./CMakeLists.txt).
> Можно скомпилировать отдельно bad.s и увидеть ошибку... а можно по-другому! (чтобы не повторялось с прошлой ошибкой)
>
> ```
> cmake .
> cmake --build .
> ```
>
>> ```
>> [ 33%] Building ASM object CMakeFiles/mai_lab_bits.dir/bad.s.o
>> /Users/nevrozq/Code/mai-lab-c-compilation/bad.s:5:5: error: unrecognized instruction mnemonic
>> ```
> Это ошибка ассемблирования, т. к. вылетает она во время билдинга `.s.o` файла!
