# Структура проекта linuxcnc_sv660n_qtdragon

Конфигурация LinuxCNC для приводов Inovance SV660N с GUI QtDragon. Базируется на примере leadshine EL8, адаптирована под PDO из выгрузок SV660N.

## Основные файлы
- `SV660N_machine.ini` — INI: DISPLAY=qtdragon, JOINTS=4 (XYZ + шпиндель S), период сервопотока 1 мс, HOMEMOD=always_homed, лимиты/скорости осей.
- `SV660N_machine.hal` — главный HAL: EtherCAT (`lcec_conf ethercat-sv660n.xml`), 4 инстанса `cia402`, `servospindle` для шпинделя, near/dbounce, сетки сигналов для осей и шпинделя (CSP), минимум опmode-переключений (opmode-display=8).
- `ethercat-sv660n.xml` — EtherCAT карта PDO для 4 приводов SV660N (vid `0x00100000`, pid `0x000c010d`): RxPDO 1701 → 6040, 607A, 60B8, 60FE:01; TxPDO 1B01 → 603F, 6041, 6064, 6077, 60F4, 60B9, 60BA, 60BC, 60FD; SDO 6060=8 (CSP).
- `linuxcnc.var` — файл параметров G-кода (переменные).
- `README.md` — краткое описание запуска и что настроить.

## Компоненты HAL (.comp)
- `cia402.comp` — интерфейс CiA402 (стейт-машина, масштабирование pos/vel, homing).
- `servospindle.comp` — вспомогательный компонент для шпинделя-сервопривода (индекс, pos offset, rpm).
- `always_homed.comp`, `el8_homecomp.comp` — homing-модули (скелет и кастомный пример).

## Дополнительные HAL/UI
- `pyvcp_panel.xml` / `pyvcp_panel.hal` — пример PyVCP панели (момент, температура, реле и т.д.).
- `xhc-whb04b.hal` — привязка пульта xhc-whb04b-6 к halui/mdi/spindle.

## Связи и загрузка
1. LinuxCNC читает `SV660N_machine.ini` → подключает `SV660N_machine.hal` (и при необходимости PyVCP/xhc).
2. `SV660N_machine.hal` грузит EtherCAT (`lcec` + `ethercat-sv660n.xml`), создает `cia402.0..3`, связывает их с `motion/joint.*`, настраивает шпиндель через `servospindle`.
3. PyVCP/xhc используют пины EtherCAT/halui по своим файлам.

## Что настраивать под станок
- Масштаб `pos-scale` и знак осей в `SV660N_machine.hal`.
- Лимиты/скорости в `SV660N_machine.ini`.
- PDO/SDO в `ethercat-sv660n.xml`, если у реальных SV660N другая карта (например, нужен 60FF/606C/6061).
- Homing: сейчас `always_homed`; при реальных датчиках заменить на подходящий модуль и подключить пины.
