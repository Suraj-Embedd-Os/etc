/*
 * Code generated from START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set RX_SCRN pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void RX_SCRN_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set RX_SCRN data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void RX_SCRN_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(4, dir);
}

/**
 * \brief Set RX_SCRN input/sense configuration
 *
 * Enable/disable RX_SCRN digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void RX_SCRN_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(4, isc);
}

/**
 * \brief Set RX_SCRN inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on RX_SCRN is inverted
 *                     false = I/O on RX_SCRN is not inverted
 */
static inline void RX_SCRN_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(4, inverted);
}

/**
 * \brief Set RX_SCRN level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void RX_SCRN_set_level(const bool level)
{
	PORTA_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on RX_SCRN
 *
 * Toggle the pin level
 */
static inline void RX_SCRN_toggle_level()
{
	PORTA_toggle_pin_level(4);
}

/**
 * \brief Get level on RX_SCRN
 *
 * Reads the level on a pin
 */
static inline bool RX_SCRN_get_level()
{
	return PORTA_get_pin_level(4);
}

/**
 * \brief Set TX_SCRN pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void TX_SCRN_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set TX_SCRN data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void TX_SCRN_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(5, dir);
}

/**
 * \brief Set TX_SCRN input/sense configuration
 *
 * Enable/disable TX_SCRN digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void TX_SCRN_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(5, isc);
}

/**
 * \brief Set TX_SCRN inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on TX_SCRN is inverted
 *                     false = I/O on TX_SCRN is not inverted
 */
static inline void TX_SCRN_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(5, inverted);
}

/**
 * \brief Set TX_SCRN level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void TX_SCRN_set_level(const bool level)
{
	PORTA_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on TX_SCRN
 *
 * Toggle the pin level
 */
static inline void TX_SCRN_toggle_level()
{
	PORTA_toggle_pin_level(5);
}

/**
 * \brief Get level on TX_SCRN
 *
 * Reads the level on a pin
 */
static inline bool TX_SCRN_get_level()
{
	return PORTA_get_pin_level(5);
}

/**
 * \brief Set TX0 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void TX0_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set TX0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void TX0_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(4, dir);
}

/**
 * \brief Set TX0 input/sense configuration
 *
 * Enable/disable TX0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void TX0_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(4, isc);
}

/**
 * \brief Set TX0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on TX0 is inverted
 *                     false = I/O on TX0 is not inverted
 */
static inline void TX0_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(4, inverted);
}

/**
 * \brief Set TX0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void TX0_set_level(const bool level)
{
	PORTB_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on TX0
 *
 * Toggle the pin level
 */
static inline void TX0_toggle_level()
{
	PORTB_toggle_pin_level(4);
}

/**
 * \brief Get level on TX0
 *
 * Reads the level on a pin
 */
static inline bool TX0_get_level()
{
	return PORTB_get_pin_level(4);
}

/**
 * \brief Set RX0 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void RX0_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set RX0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void RX0_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(5, dir);
}

/**
 * \brief Set RX0 input/sense configuration
 *
 * Enable/disable RX0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void RX0_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(5, isc);
}

/**
 * \brief Set RX0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on RX0 is inverted
 *                     false = I/O on RX0 is not inverted
 */
static inline void RX0_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(5, inverted);
}

/**
 * \brief Set RX0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void RX0_set_level(const bool level)
{
	PORTB_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on RX0
 *
 * Toggle the pin level
 */
static inline void RX0_toggle_level()
{
	PORTB_toggle_pin_level(5);
}

/**
 * \brief Get level on RX0
 *
 * Reads the level on a pin
 */
static inline bool RX0_get_level()
{
	return PORTB_get_pin_level(5);
}

/**
 * \brief Set RX_WIFI pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void RX_WIFI_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set RX_WIFI data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void RX_WIFI_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(0, dir);
}

/**
 * \brief Set RX_WIFI input/sense configuration
 *
 * Enable/disable RX_WIFI digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void RX_WIFI_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(0, isc);
}

/**
 * \brief Set RX_WIFI inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on RX_WIFI is inverted
 *                     false = I/O on RX_WIFI is not inverted
 */
static inline void RX_WIFI_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(0, inverted);
}

/**
 * \brief Set RX_WIFI level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void RX_WIFI_set_level(const bool level)
{
	PORTC_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on RX_WIFI
 *
 * Toggle the pin level
 */
static inline void RX_WIFI_toggle_level()
{
	PORTC_toggle_pin_level(0);
}

/**
 * \brief Get level on RX_WIFI
 *
 * Reads the level on a pin
 */
static inline bool RX_WIFI_get_level()
{
	return PORTC_get_pin_level(0);
}

/**
 * \brief Set TX_WIFI pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void TX_WIFI_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set TX_WIFI data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void TX_WIFI_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(1, dir);
}

/**
 * \brief Set TX_WIFI input/sense configuration
 *
 * Enable/disable TX_WIFI digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void TX_WIFI_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(1, isc);
}

/**
 * \brief Set TX_WIFI inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on TX_WIFI is inverted
 *                     false = I/O on TX_WIFI is not inverted
 */
static inline void TX_WIFI_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(1, inverted);
}

/**
 * \brief Set TX_WIFI level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void TX_WIFI_set_level(const bool level)
{
	PORTC_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on TX_WIFI
 *
 * Toggle the pin level
 */
static inline void TX_WIFI_toggle_level()
{
	PORTC_toggle_pin_level(1);
}

/**
 * \brief Get level on TX_WIFI
 *
 * Reads the level on a pin
 */
static inline bool TX_WIFI_get_level()
{
	return PORTC_get_pin_level(1);
}

/**
 * \brief Set second_stage_heat pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void second_stage_heat_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set second_stage_heat data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void second_stage_heat_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(4, dir);
}

/**
 * \brief Set second_stage_heat input/sense configuration
 *
 * Enable/disable second_stage_heat digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void second_stage_heat_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(4, isc);
}

/**
 * \brief Set second_stage_heat inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on second_stage_heat is inverted
 *                     false = I/O on second_stage_heat is not inverted
 */
static inline void second_stage_heat_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(4, inverted);
}

/**
 * \brief Set second_stage_heat level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void second_stage_heat_set_level(const bool level)
{
	PORTC_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on second_stage_heat
 *
 * Toggle the pin level
 */
static inline void second_stage_heat_toggle_level()
{
	PORTC_toggle_pin_level(4);
}

/**
 * \brief Get level on second_stage_heat
 *
 * Reads the level on a pin
 */
static inline bool second_stage_heat_get_level()
{
	return PORTC_get_pin_level(4);
}

/**
 * \brief Set second_stage_cool pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void second_stage_cool_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set second_stage_cool data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void second_stage_cool_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(5, dir);
}

/**
 * \brief Set second_stage_cool input/sense configuration
 *
 * Enable/disable second_stage_cool digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void second_stage_cool_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(5, isc);
}

/**
 * \brief Set second_stage_cool inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on second_stage_cool is inverted
 *                     false = I/O on second_stage_cool is not inverted
 */
static inline void second_stage_cool_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(5, inverted);
}

/**
 * \brief Set second_stage_cool level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void second_stage_cool_set_level(const bool level)
{
	PORTC_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on second_stage_cool
 *
 * Toggle the pin level
 */
static inline void second_stage_cool_toggle_level()
{
	PORTC_toggle_pin_level(5);
}

/**
 * \brief Get level on second_stage_cool
 *
 * Reads the level on a pin
 */
static inline bool second_stage_cool_get_level()
{
	return PORTC_get_pin_level(5);
}

/**
 * \brief Set first_stage_cool pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void first_stage_cool_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(6, pull_mode);
}

/**
 * \brief Set first_stage_cool data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void first_stage_cool_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(6, dir);
}

/**
 * \brief Set first_stage_cool input/sense configuration
 *
 * Enable/disable first_stage_cool digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void first_stage_cool_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(6, isc);
}

/**
 * \brief Set first_stage_cool inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on first_stage_cool is inverted
 *                     false = I/O on first_stage_cool is not inverted
 */
static inline void first_stage_cool_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(6, inverted);
}

/**
 * \brief Set first_stage_cool level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void first_stage_cool_set_level(const bool level)
{
	PORTC_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on first_stage_cool
 *
 * Toggle the pin level
 */
static inline void first_stage_cool_toggle_level()
{
	PORTC_toggle_pin_level(6);
}

/**
 * \brief Get level on first_stage_cool
 *
 * Reads the level on a pin
 */
static inline bool first_stage_cool_get_level()
{
	return PORTC_get_pin_level(6);
}

/**
 * \brief Set Hum pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Hum_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(7, pull_mode);
}

/**
 * \brief Set Hum data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Hum_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(7, dir);
}

/**
 * \brief Set Hum input/sense configuration
 *
 * Enable/disable Hum digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void Hum_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(7, isc);
}

/**
 * \brief Set Hum inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on Hum is inverted
 *                     false = I/O on Hum is not inverted
 */
static inline void Hum_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(7, inverted);
}

/**
 * \brief Set Hum level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Hum_set_level(const bool level)
{
	PORTC_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on Hum
 *
 * Toggle the pin level
 */
static inline void Hum_toggle_level()
{
	PORTC_toggle_pin_level(7);
}

/**
 * \brief Get level on Hum
 *
 * Reads the level on a pin
 */
static inline bool Hum_get_level()
{
	return PORTC_get_pin_level(7);
}

/**
 * \brief Set Mode_A pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Mode_A_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set Mode_A data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Mode_A_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(0, dir);
}

/**
 * \brief Set Mode_A input/sense configuration
 *
 * Enable/disable Mode_A digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void Mode_A_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(0, isc);
}

/**
 * \brief Set Mode_A inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on Mode_A is inverted
 *                     false = I/O on Mode_A is not inverted
 */
static inline void Mode_A_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(0, inverted);
}

/**
 * \brief Set Mode_A level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Mode_A_set_level(const bool level)
{
	PORTD_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on Mode_A
 *
 * Toggle the pin level
 */
static inline void Mode_A_toggle_level()
{
	PORTD_toggle_pin_level(0);
}

/**
 * \brief Get level on Mode_A
 *
 * Reads the level on a pin
 */
static inline bool Mode_A_get_level()
{
	return PORTD_get_pin_level(0);
}

/**
 * \brief Set Mode_B pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Mode_B_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set Mode_B data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Mode_B_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(1, dir);
}

/**
 * \brief Set Mode_B input/sense configuration
 *
 * Enable/disable Mode_B digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void Mode_B_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(1, isc);
}

/**
 * \brief Set Mode_B inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on Mode_B is inverted
 *                     false = I/O on Mode_B is not inverted
 */
static inline void Mode_B_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(1, inverted);
}

/**
 * \brief Set Mode_B level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Mode_B_set_level(const bool level)
{
	PORTD_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on Mode_B
 *
 * Toggle the pin level
 */
static inline void Mode_B_toggle_level()
{
	PORTD_toggle_pin_level(1);
}

/**
 * \brief Get level on Mode_B
 *
 * Reads the level on a pin
 */
static inline bool Mode_B_get_level()
{
	return PORTD_get_pin_level(1);
}

/**
 * \brief Set OTA1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void OTA1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set OTA1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void OTA1_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(2, dir);
}

/**
 * \brief Set OTA1 input/sense configuration
 *
 * Enable/disable OTA1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void OTA1_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(2, isc);
}

/**
 * \brief Set OTA1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on OTA1 is inverted
 *                     false = I/O on OTA1 is not inverted
 */
static inline void OTA1_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(2, inverted);
}

/**
 * \brief Set OTA1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void OTA1_set_level(const bool level)
{
	PORTD_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on OTA1
 *
 * Toggle the pin level
 */
static inline void OTA1_toggle_level()
{
	PORTD_toggle_pin_level(2);
}

/**
 * \brief Get level on OTA1
 *
 * Reads the level on a pin
 */
static inline bool OTA1_get_level()
{
	return PORTD_get_pin_level(2);
}

/**
 * \brief Set TEST_LED pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void TEST_LED_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set TEST_LED data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void TEST_LED_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(3, dir);
}

/**
 * \brief Set TEST_LED input/sense configuration
 *
 * Enable/disable TEST_LED digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void TEST_LED_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(3, isc);
}

/**
 * \brief Set TEST_LED inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on TEST_LED is inverted
 *                     false = I/O on TEST_LED is not inverted
 */
static inline void TEST_LED_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(3, inverted);
}

/**
 * \brief Set TEST_LED level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void TEST_LED_set_level(const bool level)
{
	PORTD_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on TEST_LED
 *
 * Toggle the pin level
 */
static inline void TEST_LED_toggle_level()
{
	PORTD_toggle_pin_level(3);
}

/**
 * \brief Get level on TEST_LED
 *
 * Reads the level on a pin
 */
static inline bool TEST_LED_get_level()
{
	return PORTD_get_pin_level(3);
}

/**
 * \brief Set Dehum pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Dehum_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTE_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set Dehum data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Dehum_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(3, dir);
}

/**
 * \brief Set Dehum input/sense configuration
 *
 * Enable/disable Dehum digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void Dehum_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(3, isc);
}

/**
 * \brief Set Dehum inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on Dehum is inverted
 *                     false = I/O on Dehum is not inverted
 */
static inline void Dehum_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(3, inverted);
}

/**
 * \brief Set Dehum level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Dehum_set_level(const bool level)
{
	PORTE_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on Dehum
 *
 * Toggle the pin level
 */
static inline void Dehum_toggle_level()
{
	PORTE_toggle_pin_level(3);
}

/**
 * \brief Get level on Dehum
 *
 * Reads the level on a pin
 */
static inline bool Dehum_get_level()
{
	return PORTE_get_pin_level(3);
}

/**
 * \brief Set AUX1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void AUX1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTF_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set AUX1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void AUX1_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(0, dir);
}

/**
 * \brief Set AUX1 input/sense configuration
 *
 * Enable/disable AUX1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void AUX1_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(0, isc);
}

/**
 * \brief Set AUX1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on AUX1 is inverted
 *                     false = I/O on AUX1 is not inverted
 */
static inline void AUX1_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(0, inverted);
}

/**
 * \brief Set AUX1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void AUX1_set_level(const bool level)
{
	PORTF_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on AUX1
 *
 * Toggle the pin level
 */
static inline void AUX1_toggle_level()
{
	PORTF_toggle_pin_level(0);
}

/**
 * \brief Get level on AUX1
 *
 * Reads the level on a pin
 */
static inline bool AUX1_get_level()
{
	return PORTF_get_pin_level(0);
}

/**
 * \brief Set AUX2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void AUX2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTF_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set AUX2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void AUX2_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(1, dir);
}

/**
 * \brief Set AUX2 input/sense configuration
 *
 * Enable/disable AUX2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void AUX2_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(1, isc);
}

/**
 * \brief Set AUX2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on AUX2 is inverted
 *                     false = I/O on AUX2 is not inverted
 */
static inline void AUX2_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(1, inverted);
}

/**
 * \brief Set AUX2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void AUX2_set_level(const bool level)
{
	PORTF_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on AUX2
 *
 * Toggle the pin level
 */
static inline void AUX2_toggle_level()
{
	PORTF_toggle_pin_level(1);
}

/**
 * \brief Get level on AUX2
 *
 * Reads the level on a pin
 */
static inline bool AUX2_get_level()
{
	return PORTF_get_pin_level(1);
}

/**
 * \brief Set PWM_C02 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void PWM_C02_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTF_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set PWM_C02 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PWM_C02_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(4, dir);
}

/**
 * \brief Set PWM_C02 input/sense configuration
 *
 * Enable/disable PWM_C02 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PWM_C02_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(4, isc);
}

/**
 * \brief Set PWM_C02 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PWM_C02 is inverted
 *                     false = I/O on PWM_C02 is not inverted
 */
static inline void PWM_C02_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(4, inverted);
}

/**
 * \brief Set PWM_C02 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PWM_C02_set_level(const bool level)
{
	PORTF_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on PWM_C02
 *
 * Toggle the pin level
 */
static inline void PWM_C02_toggle_level()
{
	PORTF_toggle_pin_level(4);
}

/**
 * \brief Get level on PWM_C02
 *
 * Reads the level on a pin
 */
static inline bool PWM_C02_get_level()
{
	return PORTF_get_pin_level(4);
}

/**
 * \brief Set RYD pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void RYD_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTF_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set RYD data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void RYD_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(5, dir);
}

/**
 * \brief Set RYD input/sense configuration
 *
 * Enable/disable RYD digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void RYD_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(5, isc);
}

/**
 * \brief Set RYD inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on RYD is inverted
 *                     false = I/O on RYD is not inverted
 */
static inline void RYD_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(5, inverted);
}

/**
 * \brief Set RYD level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void RYD_set_level(const bool level)
{
	PORTF_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on RYD
 *
 * Toggle the pin level
 */
static inline void RYD_toggle_level()
{
	PORTF_toggle_pin_level(5);
}

/**
 * \brief Get level on RYD
 *
 * Reads the level on a pin
 */
static inline bool RYD_get_level()
{
	return PORTF_get_pin_level(5);
}

/**
 * \brief Set RESET pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void RESET_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTF_set_pin_pull_mode(6, pull_mode);
}

/**
 * \brief Set RESET data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void RESET_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(6, dir);
}

/**
 * \brief Set RESET input/sense configuration
 *
 * Enable/disable RESET digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void RESET_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(6, isc);
}

/**
 * \brief Set RESET inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on RESET is inverted
 *                     false = I/O on RESET is not inverted
 */
static inline void RESET_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(6, inverted);
}

/**
 * \brief Set RESET level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void RESET_set_level(const bool level)
{
	PORTF_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on RESET
 *
 * Toggle the pin level
 */
static inline void RESET_toggle_level()
{
	PORTF_toggle_pin_level(6);
}

/**
 * \brief Get level on RESET
 *
 * Reads the level on a pin
 */
static inline bool RESET_get_level()
{
	return PORTF_get_pin_level(6);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
