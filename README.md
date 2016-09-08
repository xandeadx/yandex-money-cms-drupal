##yanexmoney-drupal-commerce-ubercart

Модуль оплаты yanexmoney-drupal-commerce-ubercart необходим для интеграции с сервисом [Яндекс.Касса](http://kassa.yandex.ru/) на базе CMS Drupal и компонента [Drupal commerce](https://www.drupal.org/project/commerce) или [Drupal ubercart](https://www.drupal.org/project/ubercart).

 Доступные платежные методы, если вы работаете как юридические лицо:
* **Банковские карты** -  Visa (включая Electron), MasterCard и Maestro любого банка мира
* **Электронные деньги** - Яндекс.Деньги, WebMoney и QIWI Wallet
* **Наличные** - [Более 170 тысяч пунктов](https://money.yandex.ru/pay/doc.xml?id=526209) оплаты по России
* **Баланс телефона** - Билайн, МегаФон и МТС
* **Интернет банкинг** - Альфа-Клик, Сбербанк Онлайн, MasterPass и Промсвязьбанк
* **Кредитование** - Доверительный платеж (Куппи.ру)

###Требования к CMS Drupal:
* версия 7;
* компонент Commerce или Ubercart.
Модуль тестировался на Ubercart 7.x-3.8 и Commerce 7.x-1.10

###Установка модуля
Для установки данного модуля необходимо распаковать содержимое [архива](https://github.com/yandex-money/yandex-money-cms-drupal/archive/master.zip) в папку `/sites/all/modules` вашего сайта и активировать модули из административной панели.
Далее рекомендуем следовать пунктам [инструкции](http://kassa.yandex.ru/files/drupal.pdf).

Пожалуйста, обязательно делайте бекапы!

Примечание. Для перевода интерфейса модуля на русский язык необходимо активировать модуль `Locale` и импортировать файл `ru-ru.po` через меню `Конфигурация`-`Перевод интерфейса`- вкладка `Импорт`.

###Список дел
- [ ] Добавить обработку уведомлений для p2p

###Лицензионный договор.
Любое использование Вами программы означает полное и безоговорочное принятие Вами условий лицензионного договора, размещенного по адресу https://money.yandex.ru/doc.xml?id=527132 (далее – «Лицензионный договор»). 
Если Вы не принимаете условия Лицензионного договора в полном объёме, Вы не имеете права использовать программу в каких-либо целях.

###Нашли ошибку или у вас есть предложение по улучшению модуля?
Пишите нам cms@yamoney.ru
При обращении необходимо:
* Указать наименование CMS и компонента магазина, а также их версии
* Указать версию платежного модуля (доступна в списке меню `Модули`)
* Описать проблему или предложение
* Приложить снимок экрана (для большей информативности)