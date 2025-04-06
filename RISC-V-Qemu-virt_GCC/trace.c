#include "trace_macros.h"
#include "FreeRTOS.h"
#include "task.h"

struct log_record
{
    uint64_t timestamp;
    uint8_t event_id;
    uint32_t event_info;

} __attribute__((packed));

#define TASK_NAME_LENGTH 20

struct task_info
{
    uint32_t task_handle;
    char task_name[TASK_NAME_LENGTH];
} __attribute__((packed));

#define CLINT_BASE 0x2000000
#define MTIME (CLINT_BASE + 0xBFF8)
#define TIMER_FREQ 10000000 // 10 MHz

#define trace_buffer_len 1024 * 1024 / sizeof(struct log_record) - 100
#define task_info_len 100 * sizeof(struct log_record) / sizeof(struct task_info)

__attribute__((section(".trace_section"))) volatile struct log_record trace_buffer[trace_buffer_len];
__attribute__((section(".trace_section"))) volatile struct task_info task_info_buffer[task_info_len];

static inline uint64_t get_mtime()
{
    return *(volatile uint64_t *)MTIME;
}

uint64_t get_time_ns()
{
    return get_mtime() * (1000000000 / TIMER_FREQ);
}

uint64_t get_time_ms()
{
    return get_mtime() / (TIMER_FREQ / 1000);
}

static uint32_t trace_index = 100;

inline void log_event(uint32_t event_id, uint32_t data)
{
    uint64_t timeNs = get_time_ns();
    // const char *task_name = pcTaskGetName(NULL);
    if (trace_index < trace_buffer_len)
    {
        trace_buffer[trace_index++] = (struct log_record){timeNs, event_id, data};
    }
}

static uint32_t task_info_index = 0;

inline void log_task_name(uint32_t task_id, char *task_name)
{
    task_info_buffer[task_info_index].task_handle = task_id;
    for (int i = 0; i < TASK_NAME_LENGTH; i++)
    {
        char task_name_char = task_name[i];
        task_info_buffer[task_info_index].task_name[i] = task_name_char;
        if (task_name_char == 0) break;
    }
    task_info_index++;
}