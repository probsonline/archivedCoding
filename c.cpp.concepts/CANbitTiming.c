#include <stdio.h>
#include <stdlib.h>

#define  EXIT           0
#define  MPC555         1
#define  MCF5282        2
#define  MCF548x        3

#define  OK             0



/* Controller constants. */
#define  IPT            2              /* Information processing timing. */



/* Macros */
#define  MIN(x, y)      (x < y ? x : y)
#define  NIY             printf("Support for this processor is not implemented yet. \n");
#define  THRESHOLD       0.0009

void MCF5282_Info();
void Calculate_Bit_Timing(int sys_clock);
void PrintBitTimingHeader();
void PrintBitTiming(int prescaler, int pres_div, int pseg1, int pseg2, int sjw);

int BaudRates[] = {1000, 500, 250, 200, 125, 100, 50, 25, 20};

int main(int argc, char *argv[])
{
    int status=OK;
    int up_choice;
    int board_choice;    
    
    do
    {    
        printf("Select the micro processor\n");
        printf("[%d] Exit \n", EXIT);
        printf("[%d] MPC555 \n", MPC555);    
        printf("[%d] MCF5282 \n", MCF5282);
        printf("[%d] MCF548x \n\n", MCF548x);
        scanf("%d", &up_choice);
        
        /* Select the controller to use. */
        switch(up_choice)
        {
        case MPC555:
             NIY;
             break;
        case MCF5282:
             MCF5282_Info();
             printf("Select which board You wish to use for your design. \n");
             printf("[1] MCF5282 Digital DNA EVB \t\t");
             printf("[2] MCF5282 AVnet EVB \n");
             scanf("%d", &board_choice);
             
             switch(board_choice)
             {
             case 1:
                  /* System clock is half that of processro clock i.e. 64MHz. */
                  Calculate_Bit_Timing(64/2);
                  break;
             case 2: 
                  /* System clock is half that of processro clock i.e. 58MHz. */                  
                    Calculate_Bit_Timing(58/2);
                  break;
             default:
                  printf("Invalid board selectio\n");
             }             
             break;
        case MCF548x:
             NIY;
             break;
        default:
             printf("Improper selection.\n Restarting ....\n");
             break;             
        }
    }while(up_choice);
  
    printf("\nPausing\n");
    system("PAUSE");	
    return 0;
}


/* Info about MCF5282. */
void MCF5282_Info(void)
{
     printf("\n---------------------------------------------------------------------------\n");
     printf("\nMCF5282 incorporates a FlexCAN controller. \n");
     printf("The crystal oscillator for MCF5282 on DigitalDNA EVB is 8MHz. \n");
     printf("The crystal oscillator for MCF5282 on AVnet EVB is 7.378MHz. \n");
     printf("The system clock input to CAN is 32MHz or 29MHz depending upon whether we are using DigitalDNA EVB or ANnet EVB respectively. \n");
     printf("The formula used for CAN S-clock rate calculation is \n");
     printf("(SystemClock/2) / (Prescaler+1). \n");
     printf("\n---------------------------------------------------------------------------\n");     
}

/* Bit Timing parameter Calculator. */
void Calculate_Bit_Timing(int sys_clock)
{
     float max_s_slock;
     float s_clock;
     int pres_dev;   /* Prescaler. */
     int prog_seg;   /* Propagation segment. */
     int ph_seg1;    /* Phase segment 1. */
     int ph_seg2;    /* Phase segment 2. This is same as Timing Segment 2 (tseg2). */
     int sjw;
     int total_tq;
     int bri=0;
     
     /* Maximum possbile value of S-Clock. Prescaler is 1. 
        max_s_slock = (sys_clock/2) / (0+1);
     */
     max_s_slock = sys_clock/2.0;

     printf("\n\nNOTE: All the values displayed are in Timing Quanta \n\n");
     printf("=============================================================================\n");     
     PrintBitTimingHeader();     
     printf("\n=============================================================================\n");

     for(pres_dev=0; pres_dev<255; pres_dev++)
     {
         s_clock = (max_s_slock/ (float)(pres_dev+1));
         
         for(prog_seg=1; prog_seg<8; prog_seg++)
         {
             for(ph_seg1=1; ph_seg1<8; ph_seg1++)
             {
                 for(ph_seg2=1; ph_seg2<8; ph_seg2++)
                 {
                      sjw = MIN(ph_seg2, IPT);
                      
                      total_tq = prog_seg + ph_seg1 + ph_seg2 + 1;
                      printf("SJW.\t", sjw);
                      printf("Total T.Q.\n", total_tq);

                      for(bri=0; bri <9; bri++)
                      {
                          if(
                             ((BaudRates[bri]*total_tq/1000 - s_clock) > 0) && 
                             ((BaudRates[bri]*total_tq/1000 - s_clock) < THRESHOLD) ||
                             ((s_clock - (BaudRates[bri]*total_tq/1000)) > 0) && 
                             ((s_clock - (BaudRates[bri]*total_tq/1000)) < THRESHOLD)
                             )
                          {
                              PrintBitTiming(pres_dev, prog_seg, ph_seg1, ph_seg2, sjw);
                          }
                      }
                 }                            
             }       
         }         
     }


     printf("\n---------------------------------------------------------------------------\n");
     printf("\n*Some controllers use the notion of Timing Segment 1 and Timing Segment 2. \n");
     printf("There is not Propagation Segment then. In that case actually \n");
     printf("Timing Segment 1 =  Propagation Segment 1 + Phase Segment 1 \n");
     printf("Timing Segment 2 = Propagation Segment 2 + Phase Segment 2 \n");
     printf("\n---------------------------------------------------------------------------\n\n");          
}

/* Print routine for Bit Timing. */
void PrintBitTiming(int prescaler, int pres_div, int pseg1, int pseg2, int sjw)
{
//     printf("%d \t\t %x \t\t\t %x \t\t\t %x \t\t\t %x \n", prescaler, pres_div, pseg1, pseg2, sjw);
     printf("\n%d \t\t %d \t\t\t %d \t\t\t %d \t\t\t %d \n", prescaler, pres_div, pseg1, pseg2, sjw);
     
}

void PrintBitTimingHeader()
{
     printf("\nPrescaler\t PropagationSegment\t PhaseSegment1\t PhaseSegment2\t SJW \n");     
}

