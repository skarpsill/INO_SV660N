# Конфигурация LinuxCNC + Inovance SV660N (QtDragon)

Быстрый старт на основе примера `linuxcnc_leadshine_EL8-main`, адаптирован для приводов Inovance SV660N и интерфейса QtDragon.

## Файлы
- `SV660N_machine.ini` — INI c 4 суставами (XYZ + шпиндель S), DISPLAY=qtdragon.
- `SV660N_machine.hal` — основной HAL: EtherCAT (lcec), 4 драйва SV660N через `cia402`, шпиндель в режимах скорости, утилиты near/dbounce/servospindle.
- `ethercat-sv660n.xml` — карта EtherCAT для 4 приводов SV660N (Vendor `0x00100000`, Product `0x000c010d`) с PDO под CiA402 (6040/6041, 6060/6061, 607A, 60FF, 6064, 606C, 6077).

## Использование
1. Соберите/установите компоненты, если еще не установлены:
   ```bash
   halcompile --install linuxcnc_leadshine_EL8-main/cia402.comp
   halcompile --install linuxcnc_leadshine_EL8-main/servospindle.comp
   halcompile --install linuxcnc_leadshine_EL8-main/always_homed.comp
   ```
2. Запустите конфигурацию:
   ```bash
   linuxcnc linuxcnc_sv660n_qtdragon/SV660N_machine.ini
   ```
3. В QtDragon настройте HAL-пины/MDI по необходимости.

## Что подстроить
- Масштабы `pos-scale` и направление осей в `SV660N_machine.hal` (setp cia402.*.pos-scale).
- Лимиты и скорости в `SV660N_machine.ini`.
- PDO под реальные карты привода — при необходимости скорректируйте `ethercat-sv660n.xml` (например, добавить 606C/60FF, если заводские PDO другие).
- Homing: сейчас стоит `HOMEMOD=always_homed` для упрощения; подключите реальные датчики при необходимости.
