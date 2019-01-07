#ifndef POSTGRES_TICKET_REPOSITORY__HPP__
#define POSTGRES_TICKET_REPOSITORY__HPP__

#include "../repository/ticket_repository.hpp"
#include "postgres_db.hpp"

class PostgresTicketRepository : public TicketRepository
{
public:
    explicit PostgresTicketRepository(PostgresDB & _db);
    virtual ~PostgresTicketRepository();

    virtual void insert(const Ticket & _ticket);

private:
    PostgresDB & m_db;
};

#endif
