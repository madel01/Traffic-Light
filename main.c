
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SSD_interface.h"

void APP_voidTrafficLed(SSD_Type Copy_SSD1, SSD_Type Copy_SSD2, LED_Type Copy_Led, u8 Copy_Time);

int main(void){

	SSD_Type SSD1 = { SSD_COMMON_CATHODE , DIO_PORTA , DIO_PORTD , DIO_PIN0 };
	SSD_Type SSD2 = { SSD_COMMON_CATHODE , DIO_PORTA , DIO_PORTD , DIO_PIN1 };

	LED_Type Red    = {DIO_PORTC , DIO_PIN0 , ACTIVE_HIGH};
	LED_Type Yellow = {DIO_PORTC , DIO_PIN1 , ACTIVE_HIGH};
	LED_Type Green  = {DIO_PORTC , DIO_PIN2 , ACTIVE_HIGH};

	DIO_enumSetPortDirection( DIO_PORTA , 255 );
	//DIO_enumSetPortDirection( DIO_PORTD , 255 );
	DIO_enumSetPortDirection( DIO_PORTC , 255 );
	DIO_enumSetPinDirection ( DIO_PORTD , DIO_PIN0 , DIO_OUTPUT );
	DIO_enumSetPinDirection ( DIO_PORTD , DIO_PIN1 , DIO_OUTPUT );

	while(1){

		APP_voidTrafficLed(SSD1, SSD2, Green, 60);

		APP_voidTrafficLed(SSD1, SSD2, Yellow, 10);

		APP_voidTrafficLed(SSD1, SSD2, Red, 60);

		/*for( u8 i = 0 ; i < 6 ; i++ ){

			SSD_voidSendNumber( SSD2 , i );
			SSD_voidEnable( SSD2 );

			for(u8 j = 0 ;j < 10 ; j++){

				SSD_voidSendNumber( SSD1 , j );
				SSD_voidEnable( SSD1 );
				_delay_ms(400);
				//SSD_voidEnable( SSD1 );
				//_delay_ms(10);
				//SSD_voidDisable( SSD1 );
				//_delay_ms(10);

			}

		}*/

	}
	return 0;
}


void APP_voidTrafficLed(SSD_Type Copy_SSD1 ,SSD_Type Copy_SSD2,LED_Type Copy_Led, u8 Copy_Time){

	LED_voidOn(Copy_Led);

	for( u8 i = 0 ; i < (Copy_Time/10) ; i++ ){

		//SSD_voidSendNumber( Copy_SSD2 , i );
		//SSD_voidEnable( Copy_SSD2 );

		for(u8 j = 0 ;j < 10 ; j++){

			//SSD_voidSendNumber( Copy_SSD1 , j );

			for(u8 k =0 ;k < 20;k++){

				//SSD_voidEnable( Copy_SSD1 );
				//_delay_ms(400);
				SSD_voidSendNumber( Copy_SSD2 , i );
				SSD_voidDisable( Copy_SSD1 );
				SSD_voidEnable( Copy_SSD2 );
				_delay_ms(10);
				SSD_voidSendNumber( Copy_SSD1 , j );
				SSD_voidDisable( Copy_SSD2 );
				SSD_voidEnable( Copy_SSD1 );
				_delay_ms(10);

			}

		}

	}

	LED_voidOff(Copy_Led);
}
