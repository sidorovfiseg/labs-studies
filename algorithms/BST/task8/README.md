# Может ты скажешь ей, что ты не Леонтий?
Недавно вошедшие в список форбс 24 до 24-ех Леонид и Семен решили открыть новый бизнес.
Для этого они нашли знаменитую предпринимательницу Лизу, которая стала спонсором их стартапа.
Для успешного трейдинга ребята создали один основной аккаунт и один дополнительный.

Для хорошей отчетности перед инвестором все рискованные сделки они проводят со второго 
аккаунта. Как только второй аккаунт выходит в положительный баланс, то ребята сливают все
акции на основной аккаунт, а второй портфель очищается. 

Вы - первый разработчик в их стартапе, перед Вами стоит сложная задача реализации 
придуманной Семой и Левой системы.

С аккаунта могут приходит следующие операции:

___buy account it___ - купить акции с номером ___id___ в портфель ___account___ (может быть 
для обоих аккаунтов)

___sell account id___ - продать акции с номером ___id___ в портфеле ___account___ (может быть 
для обоих аккаунтов)

___merge___ - сливать все акции в основной портфель

После каждого объединения товарищи проводят показ результатов Лизе, поэтому при этой операции
требуется вводить ___id___ акции в отсортированном виде без пробела на конце.

# Входные данные
В первой строке подается ___n___ - число операций ___1 <= n <= 10^7___

В следующих ___n___ строках подаются команды одного из 3 видов (___buy, sell, merge___)
Гарантируется, что номер акции: ___0 <= id <= 10^9___

# Выходные данные 
При каждой операции ___merge___ вывести ___id___ акции в отсортированном виде