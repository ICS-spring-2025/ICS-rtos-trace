#include "trace_macros.h"
#include "FreeRTOS.h"
#include "task.h"

struct log_record{
    uint64_t timestamp;
    uint8_t event_id;
    uint32_t event_info;

}__attribute__((packed));

#define CLINT_BASE  0x2000000
#define MTIME       (CLINT_BASE + 0xBFF8)
#define TIMER_FREQ  10000000  // 10 MHz

static inline uint64_t get_mtime() {
    return *(volatile uint64_t *)MTIME;
}

uint64_t get_time_ns() {
    return get_mtime() * (1000000000 / TIMER_FREQ);
}

uint64_t get_time_ms() {
    return get_mtime() / (TIMER_FREQ / 1000);
}

#define trace_buffer_len 16*1024/sizeof(struct log_record)

__attribute__((section(".trace_section"))) volatile struct log_record trace_buffer[trace_buffer_len];

static uint32_t trace_index = 0;

void log_event(uint32_t event_id, uint32_t data) {   
    uint64_t timeNs = get_time_ns();
    if (trace_index < trace_buffer_len) {
        trace_buffer[trace_index++] = (struct log_record) {timeNs, event_id, data};
    }
}
