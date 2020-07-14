#include "LK.h" // Includes shared.h

void sim_main()
{
  if (rtU->read2 <= 5000.0)
  {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    rtDW->w3 = 0.0;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */

    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    rtDW->w4 = 0.0;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem5' */
  }
  else
  {
    if (rtU->read1 > 0.0)
    {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      rtDW->w3 = 0.0;

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
    }
    else if ((rtU->read1 < 0.0) && (rtU->read1 < -10000.0))
    {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      rtDW->w3 = 10000.0;

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
    }
    else
    {
      if ((rtU->read1 < 0.0) && (rtU->read1 >= -10000.0))
      {
        /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S5>/Action Port'
         */
        rtDW->w3 = rtU->read1 * -1;

        /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
      }
    }

    if ((rtU->read1 > 0.0) && (rtU->read1 > 10000.0))
    {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      rtDW->w4 = 10000.0;

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem4' */
    }
    else if ((rtU->read1 > 0.0) && (rtU->read1 <= 10000.0))
    {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      rtDW->w4 = rtU->read1;

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem6' */
    }
    else
    {
      if (rtU->read1 < 0.0)
      {
        /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem7' incorporates:
         *  ActionPort: '<S9>/Action Port'
         */
        rtDW->w4 = 0.0;

        /* End of Outputs for SubSystem: '<S1>/If Action Subsystem7' */
      }
    }
  }

  /* End of If: '<S1>/If1' */

  /* Outport: '<Root>/write3' */
  rtY->write3 = rtDW->w3;

  /* Outport: '<Root>/write4' */
  rtY->write4 = rtDW->w4;
}
