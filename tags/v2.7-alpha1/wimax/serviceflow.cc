/* This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of
 * their official duties. Pursuant to title 17 Section 105 of the United
 * States Code this software is not subject to copyright protection and
 * is in the public domain.
 * NIST assumes no responsibility whatsoever for its use by other parties,
 * and makes no guarantees, expressed or implied, about its quality,
 * reliability, or any other characteristic.
 * <BR>
 * We would appreciate acknowledgement if the software is used.
 * <BR>
 * NIST ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION AND
 * DISCLAIM ANY LIABILITY OF ANY KIND FOR ANY DAMAGES WHATSOEVER RESULTING
 * FROM THE USE OF THIS SOFTWARE.
 * </PRE></P>
 * @author  rouil
 * @changed vr@tud
 */


#include "serviceflow.h"

/**
 * Create a flow with the given parameter
 */
static int FlowIndex = 0;

ServiceFlow::ServiceFlow (Dir_t direction, ServiceFlowQosSet * activeQosSet )
{
	direction_ = direction; // assign the direction of this flow
    sfid_ = UNASSIGNED_FLOW_ID; //assign and increment flow id
    sfState_ = PROVISIONED; // since no dynamic SF has been implemented yet
    qosSet_ = activeQosSet;
}

/**
 * Pick the next available ID. Should be called by a BS to assign a unique ID
 */
void ServiceFlow::pickID ()
{
    sfid_ = FlowIndex++;
}

/**
 * Assign an ID to the service flow
 * @param id The ID to set
 */
void ServiceFlow::setSFID (int sfid)
{
    sfid_ = sfid;
}
