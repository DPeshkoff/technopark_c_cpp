# Углубленное программирование на C/C++ (индивидуальные задания)

## Индивидуальное задание №1
### Вариант #44
Составить структуру для хранения информации о международных нормативных документах: организации-эмитенте (ISO, IEEE, W3C и т.д.), виде документа (стандарт, отчет и т.д.), названии на английском языке, дате принятия и дате вступления в силу, наличии перевода на русский язык. Составить с ее использованием программу вывода информации обо всех документах, наиболее соответствующих запросу пользователя.

## Индивидуальное задание №2
### Вариант #44
Вы разрабатываете специализированную БД сотрудников для корпорации, в которой работает порядка 10к человек. По ряду причин все данные необходимо хранить в оперативной памяти. Предложите такую эффективную упаковку данных о сотруднике (его имени, фамилии, поле, возрасте, заработной плате, должности и стаже работы). С её помощью реализуйте наивный последовательный алгоритм, который позволит быстро осуществлять поиск по запросу: самые возрастные и молодые сотрудники в каждой должности с сортировкой по фамилии, а затем – распараллельте его на несколько потоков.