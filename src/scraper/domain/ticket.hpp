#ifndef TICKET__HPP__
#define TICKET__HPP__

class Ticket
{
public:
    explicit Ticket(
        long _timestamp,
        long _low,
        long _high,
        long _last,
        long _bid,
        long _ask,
        long _volume,
        long _source);
    Ticket(const Ticket &) = default;
    Ticket(Ticket &&) = default;
    virtual ~Ticket();

    long timestamp() const;
    long low() const;
    long high() const;
    long last() const;
    long bid() const;
    long ask() const;
    long volume() const;
    long source() const;

private:
    long m_timestamp;
    long m_low;
    long m_high;
    long m_last;
    long m_bid;
    long m_ask;
    long m_volume;
    long m_source;
};

#endif
