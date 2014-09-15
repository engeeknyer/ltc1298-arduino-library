/*
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; version
 *    2.1 of the License.
 *    
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *    
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
*/

#ifndef LTC1298_H_
#define LTC1298_H_

#include <inttypes.h>
#include <stdint.h>


/*    LTC Mode Definition 
      -------------------         */
#define CH0 0xC  /* Measure Chanel 0 */
#define CH1 0xE  /* Measure Chanel 1 */
#define DF0 0x8  /* Measure (Chanel 0 - Chanel 1) */
#define DF1 0xA  /* Measure (Chanel 1 - Chanel 0) */
#define LSB 0	 /* Set order LSB first */
#define MSB 1	 /* Set order MSB first */

/*    SPI Pin Definition 
      -------------------         */
#define DD_SS (1<<DDB2)    //pin 10: SS
#define DD_MOSI (1<<DDB3)  //pin 11: MOSI
#define DD_MISO (1<<DDB4)  //pin 12: MISO
#define DD_SCK (1<<DDB5)   //pin 13: SCK

void ltc1298_Init();
uint16_t ltc1298_Read(uint8_t mode, uint8_t bitOrder );



#endif
