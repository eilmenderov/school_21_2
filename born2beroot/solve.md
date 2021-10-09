# **Born2beRoot**

## Разбивка диска для бонусов

Logical Volume Manager:
```
* Vda 1		530 Mb
* Vda 2		530 Mb
* Root		10704 Mb
* Home		5404 Mb
* Var		3204 Mb
* Srv		3204 Mb
* Tmp		3204 Mb
* Var-log	4304 Mb
* Swap		2500 Mb
```

## Установка Sudo

* Substitute User and do «подменить пользователя и выполнить»:
```
$ sudo apt update
$ apt install sudo
$ dpkg -l | grep sudo
```
* Добавить пользователя в группу sudo:
```
$ adduser USER_NAME sudo
```
* Проверить пользователей в группе sudo:
```
$ getent group sudo
```


## Конфигурация sudo

* Открыть конфиг файл для настройки:
```
sudo vi /etc/sudoers.d/sudo_add_config
```
* Ограничение попыток авторизация с помощью sudo:
```
Defaults        passwd_tries=3
```
* Добавление кастомного сообщения при неправильной попытке ввода пароля:
```
Defaults        badpass_message=“<custom-error-message>"
```
* Добавление пути для ведения логов команд sudo:
```
sudo mkdir /var/log/sudo
Defaults        logfile="/var/log/sudo/<filename>"
```

* Если используется какой-то код без полномочий root (например, PHP-скрипт), опция requiretty означает, что код эксплойта не сможет напрямую обновить свои привилегии, запустив sudo:
```
Defaults        requiretty
```


## Установка ssh сервера и его конфигурация

* Установка:
```
sudo apt install openssh-server
```
* Проверка установки:
```
dpkg -l | grep ssh
```
* Конфигурация ssh:
```
Sudo vim /etc/ssh/sshd_config
Port 4242 
```
* запрет на вход от root:
```
PermitRootLogin no
```
* проверка:
```
sudo service ssh status
```


## Установка и конфигурация UFW
* установка:
```
sudo apt install ufw
dpkg -l | grep ufw
```
* включить firewall:
```
sudo ufw enable
```
* разрешить входящие соединения:
```
sudo ufw allow 4242
sudo ufw status
Sudo ufw delete number
```
* перезапуск ssh:
```
sudo systemctl restart ssh
```


## Политика безопасности пользователей

* Открыть:
```
sudo vi /etc/login.defs
```
* максимальное существование пароля пользователя в днях:
```
PASS_MAX_DAYS   30
```
* установка минимального количества дней, после которого пользователь может сменить пароль:
```
PASS_MIN_DAYS   2
```
* отправлять сообщение о необходимости смены пароля каждые 7 дней:
```
PASS_WARN_AGE   7
```


## Libpam-pwquality для настройки политики безопасности пароля

* устанавливаем пакет:
```
sudo apt install libpam-pwquality
dpkg -l | grep libpam-pwquality
```
* открыть файл конфигурации:
```
sudo vim /etc/pam.d/common-password
```
* отличие 7 букв от старого:
```
difok=7
```
* все распространяется на рут:
```
enforce_for_root
```


## USERS and GROUPS

* создание нового пользователя:
```
sudo adduser name_user
```
* проверка создания нового пользователя:
```
getent passwd name_user
```
* проверка пользователя на пароль:
```
sudo chage -l name_user
```
* создание новой группы и добавление пользователя в эту группу:
```
sudo addgroup user42
sudo adduser name_user user42
```
* проверка, что пользователь добавился в группу:
```
getent group user42
```

## Конфигурирование cron планировщика
```
sudo crontab -u root -e
```
* Скрипт расположен в директории ```/usr/local/bin/monitoring.sh```
* проверка запуска APPArmor:
```
sudo aa-status
```

# Bonus

## Linux Lighttpd MariaDB PHP (LLMP) Stack
Lighttpd — это бесплатный, безопасный и соответствующий стандартам веб-сервер с открытым исходным кодом, разработанный для высокопроизводительных сред. По сравнению с другими альтернативными веб-серверами Lighttpd потребляет очень мало ресурсов и способен обслуживать большие нагрузки, а при установке вместе с PHP и MySQL или MariaDB он может надежно обслуживать миллионы соединений. Lighty также имеет множество модулей, расширяющих его возможности.
* step 1:
```
sudo apt install lighttpd
dpkg -l | grep lighttpd
sudo ufw allow 80
```
* step 2 - Installing & Configuring MariaDB:
```
sudo apt install mariadb-server
dpkg -l | grep mariadb-server
```
* интерактивный скрипт для установки БД:
```
sudo mysql_secure_installation
Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)
Set root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```
* заход в БД
```
sudo mariadb
```
* выполняем сл. команды в mariadb:
```
CREATE DATABASE site_db;

GRANT ALL ON site_db.* TO 'USER_NAME'@'localhost' IDENTIFIED BY 'SITE_DB_PASSWORD' WITH GRANT OPTION;

mariadb -u USER_NAME -p

Enter password: SITE_DB_PASSWORD

SHOW DATABASES;
```

* установка php:
```
sudo apt install php-cgi php-mysql
```
* проверяем что php установлен:
```
dpkg -l | grep php
```
## Загрузка и установка WordPress

* установка wget - (GNU Wget) свободная неинтерактивная консольная программа для загрузки файлов по сети. Поддерживает протоколы HTTP, FTP и HTTPS, а также поддерживает работу через HTTP прокси-сервер. Программа включена почти во все дистрибутивы GNU/Linux:
```
sudo apt install wget
sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html

sudo tar -xzvf latest.tar.gz

sudo vim /var/www/html/wp-config.php 

23 define( 'DB_NAME', ‘site_db' );^M
26 define( 'DB_USER', 'USER_NAME' );^M
29 define( 'DB_PASSWORD', 'SITE_DB_PASSWORD' );
```
* конфигурирование Lightttpd:
```
$ sudo lighty-enable-mod fastcgi
$ sudo lighty-enable-mod fastcgi-php
$ sudo service lighttpd force-reload
```

## Установка FTP сервера как дополнительного сервиса.
* FTP-сервер с поддержкой IPv6 и SSL. Является FTP-сервером по умолчанию многих операционных систем, и обслуживает официальные репозитории. До 2017 года использовался на официальном FTP ядра Linux
```
$sudo apt install vsftpd

sudo ufw allow 21
sudo ufw allow 22

sudo vim /etc/vsftpd.conf
userlist_file=/etc/vsftpd.userlist
USER_NAME 
Password : Netflix2020
Password db : SITE_DB_PASSWORD
Password wordpress : SITE_DB_PASSWORD
Root password : Netflix2021
```

## Полезные команды

* сменить пароль:
```
sudo password root
```
* остановить скрипт:
```
sudo /etc/init.d/cron stop
```
* проверка текущего имени хоста:
```
Hostnamectl
```
* установка нового имени хоста:
```
hostnamectl set-hostname name_host

sudo nano /etc/hosts
```


# Теория
## Отличие Debian от CentOS
Debian - это проект, поддерживаемый и развиваемый сообществом волонтёров. Он ни на чём не основан и развивается, как стабильная и тщательно проверенная операционная система. CentOS тоже представляет собой проект, поддерживаемый сообществом. Но уже не  так, как Debian. Это дистрибутив, созданный на основе открытых исходников Red Hat Enterprice Linux корпорации Red Hat. Фактически, это тот же самый RHEL, только с вырезанным брендингом и без менеджера подписки. 
У Debian больше всего пакетов в официальных репозиториях дистрибутива и, кроме того, доступно множество сторонних PPA-репозиториев с различным дополнительным программным обеспечением или новыми версиями ПО. В качестве менеджера пакетов используется APT и формат .deb, разработанный специально для этой системы.
Новая версия Debian выходит каждые два года, однако, в пределах одной определённой версии, дистрибутив получает только обновления безопасности и исправление ошибок. Поэтому, ближе к выпуску следующей версии, большинство пакетов очень сильно устаревает. В CentOS нет точного графика релизов, поскольку он зависит от публикации исходников Red Hat.

## Различия между Aptitude и APT
Основное различие в том, что Aptitude является менеджером пакетов высокого уровня, а APT - менеджером пакетов более низкого уровня, который в принципе может использоваться другими менеджерами пакетов более высокого уровня.

APT - Advanced Packaging Tool  - это программа с открытым исходным кодом, которая позволяет устанавливать программное обеспечение для linux

Aptitude - это оболочка для APT, которая добавляет пользовательский интерфейс, и много дополнительной функциональности, например поиска пакета в интерактивном режиме, а также моментальная его установка или удаление.
Aptitude позволяет лучшее управлять пакетами чем в apt-get.

При удалении любого установленного пакета. Aptitude автоматически удаляет неиспользуемые пакеты и все их зависимости. Apt-get удаляет только то что было указанно в команде.

## Различия между SELinux и APPArmor

SELinux (SELinux) — это система принудительного контроля доступа, реализованная на уровне ядра.

AppArmor — программный инструмент упреждающей защиты, основанный на политиках безопасности (известных также как профили), которые определяют, к каким системным ресурсам и с какими привилегиями может получить доступ то или иное приложение
Также в SELinux реализована многоуровневая система обеспечения безопасности 
Наборы правил SELinux невероятно сложны, но с этой сложностью у вас больше контроля над тем, как изолированы процессы. Создание этих политик можно автоматизировать. Недостатком этой системы безопасности является то, что ее очень сложно проверить независимо.

AppArmor (и SMACK) очень прост. Профили могут быть написаны вручную людьми или созданы с использованием aa-logprof. AppArmor использует управление на основе пути, что делает систему более прозрачной и позволяет проводить независимую проверку ».

LVM — это дополнительный слой абстракции от железа, позволяющий собрать кучи разнородных дисков в один, и затем снова разбить этот один именно так как нам хочется.

есть 3 уровня абстракции:
1. PV (Physical Volume) — физические тома (это могут быть разделы или целые «неразбитые» диски)
2. VG (Volume Group) — группа томов (объединяем физические тома (PV) в группу, создаём единый диск, который будем дальше разбивать так, как нам хочется)
3. LV (Logical Volume) — логические разделы, собственно раздел нашего нового «единого диска» ака Группы Томов, который мы потом форматируем и используем как обычный раздел, обычного жёсткого диска.
