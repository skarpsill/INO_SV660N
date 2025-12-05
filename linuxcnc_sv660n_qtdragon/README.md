# Конфигурация LinuxCNC + Inovance SV660N (QtDragon)

Готовый набор INI/HAL под QtDragon и EtherCAT (lcec) для 4 линейных осей (XYZ + A) на приводах SV660N.

## Быстрый запуск QtDragon
1) Установите компоненты (один раз):
```bash
halcompile --install linuxcnc_sv660n_qtdragon/cia402.comp
halcompile --install linuxcnc_sv660n_qtdragon/always_homed.comp
```
2) Убедитесь, что EtherCAT master (IgH/lcec) работает и видит 4 слейва SV660N (vid `0x00100000`, pid `0x000c010d`).
3) Запуск QtDragon с этой конфигурацией:
```bash
linuxcnc linuxcnc_sv660n_qtdragon/SV660N_machine.ini
```
QtDragon сам подхватится как DISPLAY.

## Ключевые файлы
- `SV660N_machine.ini` — 4 сустава, DISPLAY=qtdragon, HOMEMOD=always_homed.
- `SV660N_machine.hal` — EtherCAT + 4×`cia402` (CSP) для осей XYZ A.
- `ethercat-sv660n.xml` — PDO из выгрузок SV660N: Rx 1701 → 6040, 6060, 607A, 60B8, 60FE:01; Tx 1B01 → 603F, 6041, 6061, 6064, 6077, 60F4, 60B9, 60BA, 60BC, 60FD.
- `xhc-whb04b.hal`, `pyvcp_panel.*` — опционально, если используете пульт или панель.

## Что подстроить под станок
- Масштаб/знак осей: `setp cia402.*.pos-scale` в `SV660N_machine.hal`.
- Лимиты/скорости: секции `[AXIS_*]/[JOINT_*]` в INI.
- PDO/SDO: если реальная карта другая, правьте `ethercat-sv660n.xml` (например, добавить 60FF/606C).
- Homing: вместо `always_homed` подключить датчики/кастомный homecomp при необходимости.
