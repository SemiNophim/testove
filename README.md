# Simple Console Store Application

Консольний додаток мовою C++ для управління каталогом товарів та кошиком покупок.

---

## Передумови (Prerequisites)

Для збирання та запуску проекту на вашому комп'ютері має бути встановлений компілятор C++ (GCC/g++, Clang або MSVC).

---

## Компіляція проекту (Building)

Команда компіляції залежить від вашої операційної системи та встановленого компілятора.

### Windows

* **MinGW (g++):**
  `g++ main.cpp CommandList.cpp Filedriver.cpp Product.cpp Cart.cpp -o test.exe`

* **MSVC (Microsoft Visual C++ / Developer Command Prompt):**
  `cl /EHsc main.cpp CommandList.cpp Filedriver.cpp Product.cpp Cart.cpp /Fe:test.exe`

---

### Linux / macOS

Використовуйте стандартний компілятор `g++`:

`g++ main.cpp CommandList.cpp Filedriver.cpp Product.cpp Cart.cpp -o test`

---

## Запуск програми (Execution)

Після успішної компіляції у вашій директорії з'явиться виконуваний файл:

* **Windows:**
  `test.exe`

* **Linux / macOS:**
  `./test`

---

## Доступні команди в програмі

* `list` — переглянути каталог доступних товарів.
* `add <id> <count>` — додати товар з вказаним ID та кількістю до кошика.
* `remove <id> <count>` — видалити товар з кошика.
* `cart` — переглянути вміст кошика та підсумкову вартість.
* `checkout` — оформити замовлення.
* `exit` — завершити роботу програми.

