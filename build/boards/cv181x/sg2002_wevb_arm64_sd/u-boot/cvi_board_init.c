
static void set_rtc_register_for_power(void)
{
	mmio_write_32(0x050250AC, 0x2);
	mmio_write_32(0x050260D0, 0x3);
	mmio_write_32(0x03001098, 0x0);
	mmio_write_32(0x0300109C, 0x0);
	mmio_write_32(0x03001090, 0x0);
	mmio_write_32(0x03001094, 0x0);
	mmio_write_32(0x05027084, 0x0);
	mmio_write_32(0x05027088, 0x0);
	mmio_write_32(0x0502708C, 0x0);
	mmio_write_32(0x05027090, 0x0);
	mmio_write_32(0x050260BC, 0x1700);
	mmio_write_32(0x05026128, 0x0);
}

int cvi_board_init(void)
{
	PINMUX_CONFIG(CAM_MCLK0, CAM_MCLK0);

	PINMUX_CONFIG(IIC3_SCL, IIC3_SCL);
	PINMUX_CONFIG(IIC3_SDA, IIC3_SDA);


	//##########I2C0 ######### demo board i2c0 need using gpio to simulate i2c
	/*touch panel*/
	PINMUX_CONFIG(IIC0_SCL, XGPIOA_28);
	PINMUX_CONFIG(IIC0_SDA, XGPIOA_29);
	PINMUX_CONFIG(VIVO_D9, XGPIOB_12);
	PINMUX_CONFIG(VIVO_D8, XGPIOB_13);
	//#########SENSOR_PWR_EN
	PINMUX_CONFIG(CAM_PD0, XGPIOA_1);
	//#########WIFI
	pinmux_config(PINMUX_SDIO1);
	PINMUX_CONFIG(VIVO_D10, XGPIOB_11);
	//########AHD
	PINMUX_CONFIG(ADC3, IIC4_SCL);
	PINMUX_CONFIG(ADC2, IIC4_SDA);

	PINMUX_CONFIG(USB_VBUS_EN, XGPIOB_5);
	PINMUX_CONFIG(PAD_MIPIRX5N, XGPIOC_0);

	//#######tp
	PINMUX_CONFIG(VIVO_D9, XGPIOB_12);
	PINMUX_CONFIG(VIVO_D8, XGPIOB_13);
	//########panel
	PINMUX_CONFIG(JTAG_CPU_TRST, XGPIOA_20);
	pinmux_config(PINMUX_DSI);
	PINMUX_CONFIG(AUX0, XGPIOA_30);
	PINMUX_CONFIG(PWR_GPIO0, PWR_GPIO_0);

	//######## mipi-dsi
	PINMUX_CONFIG(PAD_MIPI_TXM0, XGPIOC_12);
	PINMUX_CONFIG(PAD_MIPI_TXP0, XGPIOC_13);
	PINMUX_CONFIG(PAD_MIPI_TXM1, XGPIOC_14);
	PINMUX_CONFIG(PAD_MIPI_TXP1, XGPIOC_15);
	PINMUX_CONFIG(PAD_MIPI_TXM2, XGPIOC_16);
	PINMUX_CONFIG(PAD_MIPI_TXP2, XGPIOC_17);
	PINMUX_CONFIG(PAD_MIPI_TXM3, XGPIOC_20);
	PINMUX_CONFIG(PAD_MIPI_TXP3, XGPIOC_21);
	PINMUX_CONFIG(PAD_MIPI_TXM4, XGPIOC_18);
	PINMUX_CONFIG(PAD_MIPI_TXP4, XGPIOC_19);

    //######## usb
	PINMUX_CONFIG(USB_VBUS_DET, XGPIOB_6);
	set_rtc_register_for_power();

	return 0;
}
