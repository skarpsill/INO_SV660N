# Структура проекта linuxcnc_leadshine_EL8-main

Краткое описание конфигурации LinuxCNC с EtherCAT и пультом xhc-whb04b-6. Файлы лежат в корне и в основном используются напрямую из INI/HAL.

## Корневые файлы конфигурации
- `EL8_machine.ini` — основная INI-конфигурация LinuxCNC: отображение Axis GUI, кинематика trivkins (5 осей XYZAB), период сервопотока, списки HAL-файлов, параметры траектории и лимиты осей.
- `EL8_machine.hal` — главный HAL: загрузка EtherCAT (lcec), драйверов CiA402, сервошпинделя, функций near/dbounce, настройка шпинделя и осей XYZAB, базовые сети сигналов.
- `xhc-whb04b.hal` — привязка пульта xhc-whb04b-6 к halui: сигналы включения станка, режимы, макрокнопки, шпиндель, override подачи/скорости, обратная связь осей.
- `pyvcp_panel.xml` и `pyvcp_panel.hal` — панель PyVCP: индикаторы воздуха/реле, нагрузка осей, RPM/ток шпинделя, температура VFD; HAL-файл собирает данные из EtherCAT (момент, температура) и скейлит их.
- `ethercat-conf.xml` — конфигурация EtherCAT: мастер 0, slaves 0–3 (оси A,Z,Y,X Leadshine EL8), 4–6 (EK1100/EL1008/EL2008), 7 (шпиндель Metronix ARS 2310 FS); PDO-карты и SDO для включения рамп.
- `linuxcnc.var` — файл параметров G-кода (текущее состояние переменных); `linuxcnc.var.bak` — резервная копия.

## HAL-компоненты (.comp)
- `cia402.comp` — слой интерфейса CiA402: сопоставляет PDO с HAL-пинами, реализует логику состояния привода, управление режимами (CSP/CSV/Homing), масштабирование позиция/скорость.
- `servospindle.comp` — вспомогательный компонент для шпинделя-сервопривода: формирует индекс, смещение позиции, расчет RPM по приращению.
- `always_homed.comp` — шаблон/скелет homing-модуля, по умолчанию “всегда захоумлено”; содержит пример кастомного автомата хоуминга.
- `el8_homecomp.comp` — кастомный homing для EL8: выводы request/is_custom_homing, сигнал окончания от сервопривода, сброс позиции после хоуминга.

## Прочие файлы
- `.gitattributes` — настройки текстовых атрибутов Git.
- `2024-10-04_metronix_config.DCO` — бинарный/док-файл конфигурации Metronix (служебный, не подключен в HAL).
- `Metronix_ARS2310FS_modified_eeprom.sii` и `Metronix_ARS2310FS_modified_ESI.xml` — описания устройства Metronix (ESI/EEPROM) для EtherCAT.
- `always_homed.comp`, `el8_homecomp.comp` — см. выше; хранятся в корне для сборки halcompile.

## Взаимосвязи и порядок загрузки
1. LinuxCNC читает `EL8_machine.ini`, оттуда подключает `EL8_machine.hal`, `xhc-whb04b.hal`, `pyvcp_panel.hal`.
2. `EL8_machine.hal` грузит EtherCAT (`lcec` + `ethercat-conf.xml`), создает инстансы `cia402` и `servospindle`, связывает их с пинами `motion`/`joint.*`.
3. `pyvcp_panel.hal` подписывается на пины EtherCAT и передает значения в PyVCP-панель (`pyvcp_panel.xml`).
4. `xhc-whb04b.hal` привязывает пульт к halui для управления режимами/осью/шпинделем.

## Как собирать .comp
В среде LinuxCNC (dev-пакеты) собрать и установить компонент:
```bash
halcompile --install cia402.comp
halcompile --install servospindle.comp
halcompile --install el8_homecomp.comp   # или always_homed.comp
```

## Что править в первую очередь
- Лимиты и скорости осей — `EL8_machine.ini` секции `[AXIS_*]` и `[JOINT_*]`.
- Шкалы/режимы привода — `EL8_machine.hal` (setp cia402.*.pos-scale) и `cia402.comp` параметры `pos_scale`/`velo_scale`.
- EtherCAT топология/PDО — `ethercat-conf.xml`.
- Привязки пульта — `xhc-whb04b.hal` (сетевые подключения и MDI команды).
