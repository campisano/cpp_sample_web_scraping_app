#include "ticket.hpp"

Ticket::Ticket(
    long _high,
    long _last,
    long _timestamp,
    long _bid,
    long _vwap,
    long _volume,
    long _low,
    long _ask,
    long _open) :
    m_high(_high), m_last(_last), m_timestamp(_timestamp),
    m_bid(_bid), m_vwap(_vwap), m_volume(_volume),
    m_low(_low), m_ask(_ask), m_open(_open)
{
}

Ticket::~Ticket()
{
}

bool Ticket::operator ==(const Ticket & _other) const
{
    return (
        m_high == _other.m_high &&
        m_last == _other.m_last &&
        m_timestamp == _other.m_timestamp &&
        m_bid == _other.m_bid &&
        m_vwap == _other.m_vwap &&
        m_volume == _other.m_volume &&
        m_low == _other.m_low &&
        m_ask == _other.m_ask &&
        m_open == _other.m_open);
}
