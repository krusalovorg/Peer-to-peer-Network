# Peer-to-peer-Network
Hey! My name is Egor. I'm tired of the usual ~~old Internet~~ and I think it's time to change it to the *__"new" Internet__* - *__Peer-to-Peer Network__*. Peer-to-peer network is a data protection network from third parties.
# Cooperation
I will be glad to cooperate with you!
My email: asonltdlite@gmail.com or krusalovpro@gmail.com
# Building the code
Building code in Visual Studio. To build the code, you don't need any additional modules other than the installed C ++ package.
# My Goals:
- [X] Console
    - [X] Managing your client program
    - [X] Language selection (Ru or En)
- [ ] Working with networks
    - [ ] Tracking Nodes
    - [ ] Stable client
## Установить

** Все следующие операции выполняются в VS Code. ** **

1. Настройте свои учетные данные AWS.
   --`docker run --rm -ti -v ~ / .aws: /root/.aws amazon / aws-cli configure --profile commons`
   --Или `aws configure --profile commons`
2. Клонируйте и откройте этот репозиторий.
   - https://code.visualstudio.com/docs/editor/versioncontrol#_cloning-a-repository
3. Выберите «Установить» в области уведомлений «Хотите установить рекомендуемые расширения для этого репозитория?» В правом нижнем углу VSCode.
   - https://code.visualstudio.com/docs/editor/extension-gallery#_list-installed-extensions
4. Задайте 600 `~ / .ssh / gftd-exchange.pem` как` закрытый ключ, полученный от администратора` или `закрытый ключ, соответствующий публичному ключу, предоставленному администратору`.
5. Выполните следующую команду из палитры команд (Ctrl + Shift + P или ⌘ + Shift + P).
   - `Задачи: Выполнить задачи`->` Инициализировать репозиторий`-> `Продолжить без сканирования вывода задачи`
6. (Необязательно) Выберите «Открыть в контейнере» в области уведомлений. «Папка содержит файл конфигурации Dev Container ...» в правом нижнем углу VSCode.
   - https://code.visualstudio.com/docs/remote/containers

- Вы можете подключиться к RDS для разработки (Aurora Postgres) с помощью `Tasks: Run Tasks`->` AWS: create ssh tunnel to RDS instance.`.
- Вы можете выполнить `jest` для открытых в данный момент` .ts` с помощью клавиши `F5`.
  - Установите точку останова с помощью клавиши `F9`.

## ЧАСТО ЗАДАВАЕМЫЕ ВОПРОСЫ
- Я хочу использовать локальную базу данных
   --Ссылка: `.devcontainer / docker-compose.yml`,` ormconfig.ts`, `.env`
`` .sh
docker-compose -f .devcontainer / docker-compose.yml вверх -d mysql
docker-compose -f .devcontainer / docker-compose.yml exec mysql mysql -uroot
mysql> СОЗДАТЬ БАЗУ ДАННЫХ, ЕСЛИ НЕ СУЩЕСТВУЕТ external;
