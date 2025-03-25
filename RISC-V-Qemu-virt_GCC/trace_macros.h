#ifndef TRACE_MACROS_H
#define TRACE_MACROS_H

#include <stdint.h>

#include "trace_event_id.h"


void log_event(uint32_t event_id, uint32_t data);


#define traceBLOCKING_ON_QUEUE_PEEK(pxQueue) log_event(traceBLOCKING_ON_QUEUE_PEEKid, (uint32_t)(pxQueue))

#define traceBLOCKING_ON_QUEUE_RECEIVE(xQueue) log_event(traceBLOCKING_ON_QUEUE_RECEIVEid, (uint32_t)(xQueue))

#define traceBLOCKING_ON_QUEUE_SEND(xQueue) log_event(traceBLOCKING_ON_QUEUE_SENDid, (uint32_t)(xQueue))

#define traceBLOCKING_ON_STREAM_BUFFER_RECEIVE(xStreamBuffer) log_event(traceBLOCKING_ON_STREAM_BUFFER_RECEIVEid, (uint32_t)(xStreamBuffer))

#define traceBLOCKING_ON_STREAM_BUFFER_SEND(xStreamBuffer) log_event(5, (uint32_t)(xStreamBuffer))

#define traceCREATE_COUNTING_SEMAPHORE() log_event(6, 0)

#define traceCREATE_COUNTING_SEMAPHORE_FAILED() log_event(7, 0)

#define traceCREATE_MUTEX(pxNewMutex) log_event(8, (uint32_t)(pxNewMutex))

#define traceCREATE_MUTEX_FAILED() log_event(9, 0)

#define traceEVENT_GROUP_CLEAR_BITS(xEventGroup, uxBitsToClear) log_event(10, (uint32_t)(xEventGroup))

#define traceEVENT_GROUP_CLEAR_BITS_FROM_ISR(xEventGroup, uxBitsToClear) log_event(11, (uint32_t)(xEventGroup))

#define traceEVENT_GROUP_CREATE(xEventGroup) log_event(12, (uint32_t)(xEventGroup))

#define traceEVENT_GROUP_CREATE_FAILED() log_event(13, 0)

#define traceEVENT_GROUP_DELETE(xEventGroup) log_event(14, (uint32_t)(xEventGroup))

#define traceEVENT_GROUP_SET_BITS(xEventGroup, uxBitsToSet) log_event(15, (uint32_t)(xEventGroup))

#define traceEVENT_GROUP_SET_BITS_FROM_ISR(xEventGroup, uxBitsToSet) log_event(16, (uint32_t)(xEventGroup))

#define traceEVENT_GROUP_SYNC_BLOCK(xEventGroup, uxBitsToSet, uxBitsToWaitFor) log_event(17, (uint32_t)(xEventGroup))

#define traceEVENT_GROUP_WAIT_BITS_BLOCK(xEventGroup, uxBitsToWaitFor) log_event(18, (uint32_t)(xEventGroup))

#define traceFREE(pvAddress, uiSize) log_event(19, (uint32_t)(pvAddress))

#define traceGIVE_MUTEX_RECURSIVE(xMutex) log_event(20, (uint32_t)(xMutex))

#define traceGIVE_MUTEX_RECURSIVE_FAILED(xMutex) log_event(21, (uint32_t)(xMutex))

#define traceINCREASE_TICK_COUNT(xTicksToJump) log_event(22, (uint32_t)(xTicksToJump))

#define traceLOW_POWER_IDLE_BEGIN() log_event(23, 0)

#define traceLOW_POWER_IDLE_END() log_event(24, 0)

#define traceMALLOC(pvAddress, uiSize) log_event(25, (uint32_t)(pvAddress))

#define traceMOVED_TASK_TO_READY_STATE(xTask) log_event(26, (uint32_t)(xTask))

#define tracePEND_FUNC_CALL(xFunctionToPend, pvParameter1, ulParameter2, ret) log_event(27, (uint32_t)(xFunctionToPend))

#define tracePEND_FUNC_CALL_FROM_ISR(xFunctionToPend, pvParameter1, ulParameter2, ret) log_event(28, (uint32_t)(xFunctionToPend))

#define tracePOST_MOVED_TASK_TO_READY_STATE(pxTCB) log_event(29, (uint32_t)(pxTCB))

#define traceQUEUE_CREATE(pxNewQueue) log_event(30, (uint32_t)(pxNewQueue))

// #define traceQUEUE_CREATE_FAILED( ucQueueType ) log_event(31, 0)

#define traceQUEUE_DELETE(xQueue) log_event(32, (uint32_t)(xQueue))

#define traceQUEUE_PEEK(xQueue) log_event(33, (uint32_t)(xQueue))

#define traceQUEUE_PEEK_FAILED(pxQueue) log_event(34, (uint32_t)(pxQueue))

#define traceQUEUE_PEEK_FROM_ISR(pxQueue) log_event(35, (uint32_t)(pxQueue))

#define traceQUEUE_PEEK_FROM_ISR_FAILED(pxQueue) log_event(36, (uint32_t)(pxQueue))

#define traceQUEUE_REGISTRY_ADD(xQueue, pcQueueName) log_event(37, (uint32_t)(xQueue))

#define traceQUEUE_RECEIVE(xQueue) log_event(38, (uint32_t)(xQueue))

#define traceQUEUE_RECEIVE_FAILED(xQueue) log_event(39, (uint32_t)(xQueue))

#define traceQUEUE_RECEIVE_FROM_ISR(xQueue) log_event(40, (uint32_t)(xQueue))

#define traceQUEUE_RECEIVE_FROM_ISR_FAILED(xQueue) log_event(41, (uint32_t)(xQueue))

#define traceQUEUE_SEND(xQueue) log_event(42, (uint32_t)(xQueue))

#define traceQUEUE_SEND_FAILED(xQueue) log_event(43, (uint32_t)(xQueue))

#define traceQUEUE_SEND_FROM_ISR(xQueue) log_event(44, (uint32_t)(xQueue))

#define traceQUEUE_SEND_FROM_ISR_FAILED(xQueue) log_event(45, (uint32_t)(xQueue))

#define traceTAKE_MUTEX_RECURSIVE(xMutex) log_event(46, (uint32_t)(xMutex))

#define traceTAKE_MUTEX_RECURSIVE_FAILED(xMutex) log_event(47, (uint32_t)(xMutex))

#define traceTASK_CREATE(pxNewTCB) log_event(traceTASK_CREATEid, (uint32_t)(pxNewTCB->uxTCBNumber))

#define traceTASK_CREATE_FAILED(pxNewTCB) log_event(49, (uint32_t)(pxNewTCB))

#define traceTASK_DELAY() log_event(50, 0)

// #define traceTASK_DELAY_UNTIL() log_event(51, 0)

#define traceTASK_DELETE(xTask) log_event(52, (uint32_t)(xTask))

#define traceTASK_INCREMENT_TICK(xTickCount) log_event(53, (uint32_t)(xTickCount))

#define traceTASK_NOTIFY(uxIndexToNotify) log_event(54, (uint32_t)(uxIndexToNotify))

#define traceTASK_NOTIFY_FROM_ISR(uxIndexToNotify) log_event(55, (uint32_t)(uxIndexToNotify))

#define traceTASK_NOTIFY_GIVE_FROM_ISR(uxIndexToNotify) log_event(56, (uint32_t)(uxIndexToNotify))

#define traceTASK_NOTIFY_TAKE(uxIndexToWait) log_event(57, (uint32_t)(uxIndexToWait))

#define traceTASK_NOTIFY_TAKE_BLOCK(uxIndexToWait) log_event(58, (uint32_t)(uxIndexToWait))

#define traceTASK_NOTIFY_WAIT(uxIndexToWait) log_event(59, (uint32_t)(uxIndexToWait))

#define traceTASK_NOTIFY_WAIT_BLOCK(uxIndexToWait) log_event(60, (uint32_t)(uxIndexToWait))

#define traceTASK_PRIORITY_DISINHERIT(pxTCBOfMutexHolder, uxOriginalPriority) log_event(61, (uint32_t)(pxTCBOfMutexHolder))

#define traceTASK_PRIORITY_INHERIT(pxTCBOfMutexHolder, uxInheritedPriority) log_event(62, (uint32_t)(pxTCBOfMutexHolder))

#define traceTASK_PRIORITY_SET(xTask, uxNewPriority) log_event(63, (uint32_t)(xTask))

#define traceTASK_RESUME(xTask) log_event(64, (uint32_t)(xTask))

#define traceTASK_RESUME_FROM_ISR(xTask) log_event(65, (uint32_t)(xTask))

#define traceTASK_SUSPEND(xTask) log_event(66, (uint32_t)(xTask))

#define traceTASK_SWITCHED_IN() log_event(traceTASK_SWITCHED_INid, 0)

#define traceTASK_SWITCHED_OUT() log_event(traceTASK_SWITCHED_OUTid, 0)

#define traceTIMER_COMMAND_RECEIVED(pxTimer, xCommandID, xCommandValue) log_event(69, (uint32_t)(pxTimer))

#define traceTIMER_COMMAND_SEND(pxTimer, xCommandID, xOptionalValue, xStatus) log_event(70, (uint32_t)(pxTimer))

#define traceTIMER_CREATE(pxNewTimer) log_event(71, (uint32_t)(pxNewTimer))

#define traceTIMER_CREATE_FAILED() log_event(72, 0)

#define traceTIMER_EXPIRED(pxTimer) log_event(73, (uint32_t)(pxTimer))

// #define traceSTREAM_BUFFER_CREATE(xIsMessageBuffer) log_event(74, (uint32_t)(xIsMessageBuffer))

#define traceSTREAM_BUFFER_CREATE_FAILED(xIsMessageBuffer) log_event(75, (uint32_t)(xIsMessageBuffer))

#define traceSTREAM_BUFFER_CREATE_STATIC_FAILED(xReturn, xIsMessageBuffer) log_event(76, (uint32_t)(xReturn))

#define traceSTREAM_BUFFER_DELETE(xStreamBuffer) log_event(77, (uint32_t)(xStreamBuffer))



#endif // TRACE_MACROS_H
