#ifndef TICKET__HPP__
#define TICKET__HPP__

class Ticket
{
public:
    explicit Ticket(
        long _high,
        long _last,
        long _timestamp,
        long _bid,
        long _vwap,
        long _volume,
        long _low,
        long _ask,
        long _open);
    virtual ~Ticket();

    bool operator ==(const Ticket & _other) const;

    long high() const { return m_high; }
    long last() const { return m_last; }
    long timestamp() const { return m_timestamp; }
    long bid() const { return m_bid; }
    long vwap() const { return m_vwap; }
    long volume() const { return m_volume; }
    long low() const { return m_low; }
    long ask() const { return m_ask; }
    long open() const { return m_open; }

private:
    long m_high;
    long m_last;
    long m_timestamp;
    long m_bid;
    long m_vwap;
    long m_volume;
    long m_low;
    long m_ask;
    long m_open;
};

#endif
