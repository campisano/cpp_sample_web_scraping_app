#include "ticket.hpp"

Ticket::Ticket(
    long _timestamp,
    long _low,
    long _high,
    long _last,
    long _bid,
    long _ask,
    long _volume,
    long _source) :
    m_timestamp(_timestamp), m_low(_low), m_high(_high), m_last(_last),
    m_bid(_bid), m_ask(_ask), m_volume(_volume), m_source(_source)
{
}

Ticket::~Ticket()
{
}

long Ticket::timestamp() const
{
    return m_timestamp;
}
long Ticket::low() const
{
    return m_low;
}
long Ticket::high() const
{
    return m_high;
}
long Ticket::last() const
{
    return m_last;
}
long Ticket::bid() const
{
    return m_bid;
}
long Ticket::ask() const
{
    return m_ask;
}
long Ticket::volume() const
{
    return m_volume;
}
long Ticket::source() const
{
    return m_source;
}
