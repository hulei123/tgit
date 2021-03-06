var group__dspi__hal =
[
    [ "dspi_data_format_config_t", "group__dspi__hal.html#structdspi__data__format__config__t", [
      [ "bitsPerFrame", "group__dspi__hal.html#ga99d8d0dec68d5d2c1de35f8bb8b66a75", null ],
      [ "clkPhase", "group__dspi__hal.html#gad751cbe15bfe01f02088e2a36059774a", null ],
      [ "clkPolarity", "group__dspi__hal.html#ga8926c27980536d08b063f984cc5dc751", null ],
      [ "direction", "group__dspi__hal.html#ga7b5fc2246586c461ebd0325bba2e3113", null ]
    ] ],
    [ "dspi_master_config_t", "group__dspi__hal.html#structdspi__master__config__t", [
      [ "bitsPerSec", "group__dspi__hal.html#ga5d2d96624b3e3f07e10318d634bae6aa", null ],
      [ "dataConfig", "group__dspi__hal.html#ga2a0fd15ecde8e788b1b549af56a764b3", null ],
      [ "isEnabled", "group__dspi__hal.html#ga996c395bf802e45d196955b092201983", null ],
      [ "isModifiedTimingFormatEnabled", "group__dspi__hal.html#ga7fdc91f9481c4be3f2185caeb8a42b60", null ],
      [ "isRxFifoDisabled", "group__dspi__hal.html#ga1ca6a6ca8bba343b91b53259a6ca0c82", null ],
      [ "isSckContinuous", "group__dspi__hal.html#gaa20656e0643df0fcef8febbcdb47cf8d", null ],
      [ "isTxFifoDisabled", "group__dspi__hal.html#ga96143fbacfedad51747ad62eee92e773", null ],
      [ "masterInSample", "group__dspi__hal.html#ga71e1f46868e8d3011fb3c36fd3766ebb", null ],
      [ "pcsPolarity", "group__dspi__hal.html#ga377f6f21375fc570c6c8e6f1b702004c", null ],
      [ "sourceClockInHz", "group__dspi__hal.html#ga12225a413c82d42b181fbca134d33eb4", null ],
      [ "whichCtar", "group__dspi__hal.html#ga822cafb9ccbaac368bdd456f004dd7f1", null ],
      [ "whichPcs", "group__dspi__hal.html#gad3319bd8a9750355a5fa29a18044d53a", null ]
    ] ],
    [ "dspi_slave_config_t", "group__dspi__hal.html#structdspi__slave__config__t", [
      [ "dataConfig", "group__dspi__hal.html#ga390dbd59c3f76acb1071799e66548e25", null ],
      [ "isEnabled", "group__dspi__hal.html#ga0455c10258d06e9b23b72b45064b26cc", null ],
      [ "isRxFifoDisabled", "group__dspi__hal.html#ga7baead2ba09f2b30d71c51ad447ab0d6", null ],
      [ "isTxFifoDisabled", "group__dspi__hal.html#ga8f74003d1d513f571b237dde6c53d3be", null ]
    ] ],
    [ "dspi_baud_rate_divisors_t", "group__dspi__hal.html#structdspi__baud__rate__divisors__t", [
      [ "baudRateDivisor", "group__dspi__hal.html#ga7ae1b66ab2f4a6d2d1208cb28fe4f286", null ],
      [ "doubleBaudRate", "group__dspi__hal.html#ga0f48ca03566631b4a13e24450644df29", null ],
      [ "prescaleDivisor", "group__dspi__hal.html#ga02c5427e2aac3b69148d10313355ef49", null ]
    ] ],
    [ "dspi_delay_settings_config_t", "group__dspi__hal.html#structdspi__delay__settings__config__t", [
      [ "afterSck", "group__dspi__hal.html#ga5683d016c2f384b102ed3eabaf7bfb60", null ],
      [ "afterSckPre", "group__dspi__hal.html#ga99129b1eaed5e6af1454cbe5f4f14022", null ],
      [ "afterTransfer", "group__dspi__hal.html#ga7398f59255a5bcfc9e242680e32c4619", null ],
      [ "afterTransferPre", "group__dspi__hal.html#ga8d67722144e0f73b64d9782a5baa4bc6", null ],
      [ "pcsToSck", "group__dspi__hal.html#gaed5939128f1e1f5651df7f09f873a278", null ],
      [ "pcsToSckPre", "group__dspi__hal.html#gab53bc27ec935a70f9c3a8aa5808cde21", null ]
    ] ],
    [ "dspi_command_config_t", "group__dspi__hal.html#structdspi__command__config__t", [
      [ "clearTransferCount", "group__dspi__hal.html#gaa9ec273f1b798a04c27b327062f369cd", null ],
      [ "isChipSelectContinuous", "group__dspi__hal.html#ga6755300868dc9a42caf2d60f7b639b88", null ],
      [ "isEndOfQueue", "group__dspi__hal.html#ga54b6b3382baca02c2c60e6d44d72f1cf", null ],
      [ "whichCtar", "group__dspi__hal.html#gac142820d982b6ba9957cda219f75c622", null ],
      [ "whichPcs", "group__dspi__hal.html#ga5d159d52ac265c93454da2789f17aa01", null ]
    ] ],
    [ "dspi_hal_clear_status_flag", "group__dspi__hal.html#gae94ed666f4f0ba39bad1314fb60483eb", null ],
    [ "dspi_hal_configure_continuous_sck", "group__dspi__hal.html#ga39ea323bb08041ef7f635ac665b1eb23", null ],
    [ "dspi_hal_configure_data_format", "group__dspi__hal.html#ga57c809ec754493b6a8f49ae65a816f41", null ],
    [ "dspi_hal_configure_delays", "group__dspi__hal.html#ga7c8d942024ba58eda58da0e79138a5ef", null ],
    [ "dspi_hal_configure_dma", "group__dspi__hal.html#ga92adcb05dbf11cc83ca953ffb81b951a", null ],
    [ "dspi_hal_configure_doze_mode", "group__dspi__hal.html#ga44680bcbb1a07fa1a4f2e2e7a6f9778e", null ],
    [ "dspi_hal_configure_fifos", "group__dspi__hal.html#gae3eb7ed021fccc8328eb4e1a7fb1f55b", null ],
    [ "dspi_hal_configure_interrupt", "group__dspi__hal.html#ga6a77552509bef4c4359a2c5a3584a0a6", null ],
    [ "dspi_hal_configure_modified_timing_format", "group__dspi__hal.html#ga1002b4da3bada62efd1ab7448f8eb803", null ],
    [ "dspi_hal_configure_pcs_polarity", "group__dspi__hal.html#ga3d0293e3cf02d323f7a7a2e67a05be77", null ],
    [ "dspi_hal_configure_pcs_strobe", "group__dspi__hal.html#ga264d0e3c4c32a20561da83061e940858", null ],
    [ "dspi_hal_configure_rx_fifo_overwrite", "group__dspi__hal.html#ga13e1a1e60d3764af8d62013531914b4b", null ],
    [ "dspi_hal_disable", "group__dspi__hal.html#gaf04b7634e79a3e88c14a6d56ca5608d5", null ],
    [ "dspi_hal_enable", "group__dspi__hal.html#gad5281b430ceab00f8d124b706255e0ad", null ],
    [ "dspi_hal_flush_fifos", "group__dspi__hal.html#ga249f371fbeda4d698d03125a2774b475", null ],
    [ "dspi_hal_get_fifo_counter_or_pointer", "group__dspi__hal.html#ga1a2b722c49e1514e74a0ead8cb873d7c", null ],
    [ "dspi_hal_get_interrupt_config", "group__dspi__hal.html#ga48ff27d58aff46bd416cdbc68e58a1c5", null ],
    [ "dspi_hal_get_status_flag", "group__dspi__hal.html#ga36eaf2325fe91104dd009e7f7c52680d", null ],
    [ "dspi_hal_master_init", "group__dspi__hal.html#ga8b0e97aaf247f2f27330e2b67a4d9b66", null ],
    [ "dspi_hal_read_data", "group__dspi__hal.html#ga73fd5db117ff88145fb00ee4a2a5af2c", null ],
    [ "dspi_hal_reset", "group__dspi__hal.html#gaa3dc131245b628252df9a49d6fbbc59a", null ],
    [ "dspi_hal_set_baud", "group__dspi__hal.html#gaf08875a75c0ee31b1e9debd9ce35df53", null ],
    [ "dspi_hal_set_baud_divisors", "group__dspi__hal.html#gadc7156d6f3d12b5720934d389b29114f", null ],
    [ "dspi_hal_set_datain_samplepoint", "group__dspi__hal.html#gaf292a8d8cda79575cf8cd9bf48be5a3a", null ],
    [ "dspi_hal_set_master_slave", "group__dspi__hal.html#ga1a689677adaa79d0ffbcc600666ce48f", null ],
    [ "dspi_hal_slave_init", "group__dspi__hal.html#gad0c6ffe0f23d66365361d6c80ce797dc", null ],
    [ "dspi_hal_start_transfer", "group__dspi__hal.html#gaca4daed63392cf2b4c173e96b1e3ed4d", null ],
    [ "dspi_hal_stop_transfer", "group__dspi__hal.html#ga605cca1b3b77b4a5cc587d39e67fedee", null ],
    [ "dspi_hal_write_data_slave_mode", "group__dspi__hal.html#gafb500121ae5baa10f42047ba78552493", null ],
    [ "afterSck", "group__dspi__hal.html#ga5683d016c2f384b102ed3eabaf7bfb60", null ],
    [ "afterSckPre", "group__dspi__hal.html#ga99129b1eaed5e6af1454cbe5f4f14022", null ],
    [ "afterTransfer", "group__dspi__hal.html#ga7398f59255a5bcfc9e242680e32c4619", null ],
    [ "afterTransferPre", "group__dspi__hal.html#ga8d67722144e0f73b64d9782a5baa4bc6", null ],
    [ "baudRateDivisor", "group__dspi__hal.html#ga7ae1b66ab2f4a6d2d1208cb28fe4f286", null ],
    [ "bitsPerFrame", "group__dspi__hal.html#ga99d8d0dec68d5d2c1de35f8bb8b66a75", null ],
    [ "bitsPerSec", "group__dspi__hal.html#ga5d2d96624b3e3f07e10318d634bae6aa", null ],
    [ "clearTransferCount", "group__dspi__hal.html#gaa9ec273f1b798a04c27b327062f369cd", null ],
    [ "clkPhase", "group__dspi__hal.html#gad751cbe15bfe01f02088e2a36059774a", null ],
    [ "clkPolarity", "group__dspi__hal.html#ga8926c27980536d08b063f984cc5dc751", null ],
    [ "dataConfig", "group__dspi__hal.html#ga2a0fd15ecde8e788b1b549af56a764b3", null ],
    [ "dataConfig", "group__dspi__hal.html#ga390dbd59c3f76acb1071799e66548e25", null ],
    [ "direction", "group__dspi__hal.html#ga7b5fc2246586c461ebd0325bba2e3113", null ],
    [ "doubleBaudRate", "group__dspi__hal.html#ga0f48ca03566631b4a13e24450644df29", null ],
    [ "isChipSelectContinuous", "group__dspi__hal.html#ga6755300868dc9a42caf2d60f7b639b88", null ],
    [ "isEnabled", "group__dspi__hal.html#ga996c395bf802e45d196955b092201983", null ],
    [ "isEnabled", "group__dspi__hal.html#ga0455c10258d06e9b23b72b45064b26cc", null ],
    [ "isEndOfQueue", "group__dspi__hal.html#ga54b6b3382baca02c2c60e6d44d72f1cf", null ],
    [ "isModifiedTimingFormatEnabled", "group__dspi__hal.html#ga7fdc91f9481c4be3f2185caeb8a42b60", null ],
    [ "isRxFifoDisabled", "group__dspi__hal.html#ga1ca6a6ca8bba343b91b53259a6ca0c82", null ],
    [ "isRxFifoDisabled", "group__dspi__hal.html#ga7baead2ba09f2b30d71c51ad447ab0d6", null ],
    [ "isSckContinuous", "group__dspi__hal.html#gaa20656e0643df0fcef8febbcdb47cf8d", null ],
    [ "isTxFifoDisabled", "group__dspi__hal.html#ga96143fbacfedad51747ad62eee92e773", null ],
    [ "isTxFifoDisabled", "group__dspi__hal.html#ga8f74003d1d513f571b237dde6c53d3be", null ],
    [ "masterInSample", "group__dspi__hal.html#ga71e1f46868e8d3011fb3c36fd3766ebb", null ],
    [ "pcsPolarity", "group__dspi__hal.html#ga377f6f21375fc570c6c8e6f1b702004c", null ],
    [ "pcsToSck", "group__dspi__hal.html#gaed5939128f1e1f5651df7f09f873a278", null ],
    [ "pcsToSckPre", "group__dspi__hal.html#gab53bc27ec935a70f9c3a8aa5808cde21", null ],
    [ "prescaleDivisor", "group__dspi__hal.html#ga02c5427e2aac3b69148d10313355ef49", null ],
    [ "sourceClockInHz", "group__dspi__hal.html#ga12225a413c82d42b181fbca134d33eb4", null ],
    [ "whichCtar", "group__dspi__hal.html#ga822cafb9ccbaac368bdd456f004dd7f1", null ],
    [ "whichCtar", "group__dspi__hal.html#gac142820d982b6ba9957cda219f75c622", null ],
    [ "whichPcs", "group__dspi__hal.html#gad3319bd8a9750355a5fa29a18044d53a", null ],
    [ "whichPcs", "group__dspi__hal.html#ga5d159d52ac265c93454da2789f17aa01", null ]
];