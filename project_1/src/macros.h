#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

/** \addtogroup MACROS
 * @{
 */

#define BAUDRATE        B38400
#define MODEMDEVICE     "/dev/ttyS1"
#define _POSIX_SOURCE   1 /**< @brief POSIX compliant source */
#define FALSE           0
#define TRUE            1
#define OK              0
#define ERROR           -1
#define TRIES           3
#define TIMEOUT         3
#define RESET_ALARM     0

// Mesh Macros
#define FLAG            0x7E
#define A_3             0x03  /**< @brief Address for commands given by the emissor and responses by the receiver */
#define A_1             0x01  /**< @brief Address for commands given by the receiver and responses by the emissor */
#define SET             0x03
#define UA              0x07
#define DISC            0x0B
#define SET_BCC         A ^ SET
#define UA_BCC          A ^ UA

// Control Macros (there is another way of defining them)
#define C_I0            0x00  /**< @brief Control Flag for Information Frame 0 */
#define C_I1            0x40  /**< @brief Control Flag for Information Frame 1 */
#define C_RR0           0x05  /**< @brief Control Flag for ACK Frame 0 */
#define C_RR1           0x85  /**< @brief Control Flag for ACK Frame 1 */
#define C_REJ0          0x01  /**< @brief Control Flag for NACK Frame 0 */
#define C_REJ1          0x81  /**< @brief Control Flag for NACK Frame 1 */

//Byte Stuffing
#define ESCAPE          0x7D
#define ESCAPE_ESC      0x5D
#define ESCAPE_FLAG     0x5E

// packet Macros
#define DATA            0x1
#define START           0x2
#define STOP            0x3
#define FILE_SIZE       0x0
#define FILE_NAME       0x1
#define PACKET_SIZE     1024 /**< @brief Maximum packet size in bytes */

// Progress Bar Macros
#define PROGRESS_BAR_SIZE   30
#define SEPARATOR_CHAR      '#'
#define EMPTY_CHAR          '.'
#define NUM_BACKSPACES      PROGRESS_BAR_SIZE + 9

// Error generating Macros
#define PROBABILITY_BCC1    0
#define PROBABILITY_BCC2    0
#define DELAY               0

/** @} */
