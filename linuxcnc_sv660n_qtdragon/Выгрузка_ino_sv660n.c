/* Master 0, Slave 0, "InoSV660N"
 * Vendor ID:       0x00100000
 * Product code:    0x000c010d
 * Revision number: 0x00010000
 */

ec_pdo_entry_info_t slave_0_pdo_entries[] = {
    {0x6040, 0x00, 16},
    {0x607a, 0x00, 32},
    {0x60b8, 0x00, 16},
    {0x60fe, 0x01, 32},
    {0x603f, 0x00, 16},
    {0x6041, 0x00, 16},
    {0x6064, 0x00, 32},
    {0x6077, 0x00, 16},
    {0x60f4, 0x00, 32},
    {0x60b9, 0x00, 16},
    {0x60ba, 0x00, 32},
    {0x60bc, 0x00, 32},
    {0x60fd, 0x00, 32},
};

ec_pdo_info_t slave_0_pdos[] = {
    {0x1701, 4, slave_0_pdo_entries + 0},
    {0x1b01, 9, slave_0_pdo_entries + 4},
};

ec_sync_info_t slave_0_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 1, slave_0_pdos + 0, EC_WD_ENABLE},
    {3, EC_DIR_INPUT, 1, slave_0_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

/* Master 0, Slave 1, "InoSV660N"
 * Vendor ID:       0x00100000
 * Product code:    0x000c010d
 * Revision number: 0x00010000
 */

ec_pdo_entry_info_t slave_1_pdo_entries[] = {
    {0x6040, 0x00, 16},
    {0x607a, 0x00, 32},
    {0x60b8, 0x00, 16},
    {0x60fe, 0x01, 32},
    {0x603f, 0x00, 16},
    {0x6041, 0x00, 16},
    {0x6064, 0x00, 32},
    {0x6077, 0x00, 16},
    {0x60f4, 0x00, 32},
    {0x60b9, 0x00, 16},
    {0x60ba, 0x00, 32},
    {0x60bc, 0x00, 32},
    {0x60fd, 0x00, 32},
};

ec_pdo_info_t slave_1_pdos[] = {
    {0x1701, 4, slave_1_pdo_entries + 0},
    {0x1b01, 9, slave_1_pdo_entries + 4},
};

ec_sync_info_t slave_1_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 1, slave_1_pdos + 0, EC_WD_ENABLE},
    {3, EC_DIR_INPUT, 1, slave_1_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

/* Master 0, Slave 2, "InoSV660N"
 * Vendor ID:       0x00100000
 * Product code:    0x000c010d
 * Revision number: 0x00010000
 */

ec_pdo_entry_info_t slave_2_pdo_entries[] = {
    {0x6040, 0x00, 16},
    {0x607a, 0x00, 32},
    {0x60b8, 0x00, 16},
    {0x60fe, 0x01, 32},
    {0x603f, 0x00, 16},
    {0x6041, 0x00, 16},
    {0x6064, 0x00, 32},
    {0x6077, 0x00, 16},
    {0x60f4, 0x00, 32},
    {0x60b9, 0x00, 16},
    {0x60ba, 0x00, 32},
    {0x60bc, 0x00, 32},
    {0x60fd, 0x00, 32},
};

ec_pdo_info_t slave_2_pdos[] = {
    {0x1701, 4, slave_2_pdo_entries + 0},
    {0x1b01, 9, slave_2_pdo_entries + 4},
};

ec_sync_info_t slave_2_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 1, slave_2_pdos + 0, EC_WD_ENABLE},
    {3, EC_DIR_INPUT, 1, slave_2_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

/* Master 0, Slave 3, "InoSV660N"
 * Vendor ID:       0x00100000
 * Product code:    0x000c010d
 * Revision number: 0x00010000
 */

ec_pdo_entry_info_t slave_3_pdo_entries[] = {
    {0x6040, 0x00, 16},
    {0x607a, 0x00, 32},
    {0x60b8, 0x00, 16},
    {0x60fe, 0x01, 32},
    {0x603f, 0x00, 16},
    {0x6041, 0x00, 16},
    {0x6064, 0x00, 32},
    {0x6077, 0x00, 16},
    {0x60f4, 0x00, 32},
    {0x60b9, 0x00, 16},
    {0x60ba, 0x00, 32},
    {0x60bc, 0x00, 32},
    {0x60fd, 0x00, 32},
};

ec_pdo_info_t slave_3_pdos[] = {
    {0x1701, 4, slave_3_pdo_entries + 0},
    {0x1b01, 9, slave_3_pdo_entries + 4},
};

ec_sync_info_t slave_3_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 1, slave_3_pdos + 0, EC_WD_ENABLE},
    {3, EC_DIR_INPUT, 1, slave_3_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

