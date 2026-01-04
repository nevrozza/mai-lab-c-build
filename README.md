## Ввод/Вывод с комментариями
```
(lldb) breakpoint set --file main.c --line 10 // вызов функции factorial
(lldb) br s -f main.c -l 11 // print result
(lldb) run
Process 75366 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 5.1
    frame #0: 0x00000001000008c0 mai_lab_compilation`main at main.c:10:24
   7   	
   8   	int main(void) {
   9   	    const int num = 5;
-> 10  	    const int result = factorial(num);
   11  	    printf("%d! = %d\n", num, result);
   12  	    return 0;
   13  	}

(lldb) step // зайти в функцию factorial!
* thread #1, queue = 'com.apple.main-thread', stop reason = step in
    frame #0: 0x0000000100000850 mai_lab_compilation`factorial(n=5) at main.c:4:9
   1   	#include <stdio.h>
   2   	
   3   	int factorial(int n) {
-> 4   	    if (n <= 1) return 1;
   5   	    return n * factorial(n - 1);
   6   	}
   7

(lldb) next // просто шаг, никуда не входим
* thread #1, queue = 'com.apple.main-thread', stop reason = step over
    frame #0: 0x000000010000086c mai_lab_compilation`factorial(n=5) at main.c:5:12
   2   	
   3   	int factorial(int n) {
   4   	    if (n <= 1) return 1;
-> 5   	    return n * factorial(n - 1);
   6   	}
   7   	
   8   	int main(void) {

(lldb) bt // перед тем, как войти в функцию, посмотрим стек вызовов
* thread #1, queue = 'com.apple.main-thread', stop reason = step over
  * frame #0: 0x000000010000086c mai_lab_compilation`factorial(n=5) at main.c:5:12
    frame #1: 0x00000001000008c4 mai_lab_compilation`main at main.c:10:24
    frame #2: 0x000000019ac19d54 dyld`start + 7184

(lldb) step // вход в factorial(n-1) #n = 5
* thread #1, queue = 'com.apple.main-thread', stop reason = step in
    frame #0: 0x0000000100000850 mai_lab_compilation`factorial(n=4) at main.c:4:9
   1   	#include <stdio.h>
   2   	
   3   	int factorial(int n) {
-> 4   	    if (n <= 1) return 1;
   5   	    return n * factorial(n - 1);
   6   	}

(lldb) print n
(int) 4

(lldb) bt
* thread #1, queue = 'com.apple.main-thread', stop reason = step in
  * frame #0: 0x0000000100000850 mai_lab_compilation`factorial(n=4) at main.c:4:9
    frame #1: 0x0000000100000880 mai_lab_compilation`factorial(n=5) at main.c:5:16
    frame #2: 0x00000001000008c4 mai_lab_compilation`main at main.c:10:24
    frame #3: 0x000000019ac19d54 dyld`start + 7184

(lldb) n
(lldb) n // пропускаем вход в factorial(3)
* thread #1, queue = 'com.apple.main-thread', stop reason = step over
    frame #0: 0x0000000100000890 mai_lab_compilation`factorial(n=4) at main.c:6:1
   3   	int factorial(int n) {
   4   	    if (n <= 1) return 1;
   5   	    return n * factorial(n - 1);
-> 6   	}
   7   	
   8   	int main(void) {
   9   	    const int num = 5;

(lldb) n // выход из функции factorial(4)
* thread #1, queue = 'com.apple.main-thread', stop reason = step over
    frame #0: 0x0000000100000880 mai_lab_compilation`factorial(n=5) at main.c:5:16
   2   	
   3   	int factorial(int n) {
   4   	    if (n <= 1) return 1;
-> 5   	    return n * factorial(n - 1);
   6   	}
   7   	
   8   	int main(void) {

(lldb) bt // проверка стека
* thread #1, queue = 'com.apple.main-thread', stop reason = step over
  * frame #0: 0x0000000100000880 mai_lab_compilation`factorial(n=5) at main.c:5:16
    frame #1: 0x00000001000008c4 mai_lab_compilation`main at main.c:10:24
    frame #2: 0x000000019ac19d54 dyld`start + 7184

(lldb) continue // идём до следующего breakpoint (не по шагам)
* thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 8.1
    frame #0: 0x00000001000008c8 mai_lab_compilation`main at main.c:11:31
   8   	int main(void) {
   9   	    const int num = 5;
   10  	    const int result = factorial(num);
-> 11  	    printf("%d! = %d\n", num, result);
   12  	    return 0;
   13  	}

(lldb) print result
(const int) 120
(lldb) display result // выводить переменную result при каждом шаге (можно записать выражение)
Stop hook #17 added.

(lldb) n // next
5! = 120  // вывод printf'а
- Hook 17 (expr -- result)
(const int) $43 = 120
Process 75602 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = step in
    frame #0: 0x00000001000008ec mai_lab_compilation`main at main.c:12:5
   9   	    const int num = 5;
   10  	    const int result = factorial(num);
   11  	    printf("%d! = %d\n", num, result);
-> 12  	    return 0;
   13  	}

(lldb) c // continue
Process 75602 resuming
Process 75602 exited with status = 0 (0x00000000) 

Программа завершилась, удаляем display и breakpoint, если они нам больше не нужны (в этой "сессии" lldb)
(lldb) br delete // удаляет все брейкпойнты
(lldb) undisplay 17
```
