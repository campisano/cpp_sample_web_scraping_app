#include "CppUTest/TestHarness.h"
#include "../scraper/domain/aggregates/tickets/ticket.hpp"

TEST_GROUP(TicketTest)
{
    Ticket * m_ticket;

    void setup()
    {
        m_ticket = new Ticket(1, 2, 3, 4, 5, 6, 7, 8);
    }
    void teardown()
    {
        delete m_ticket;
    }
};

TEST(TicketTest, Create)
{
    CHECK(NULL != m_ticket);
    CHECK_EQUAL(1, m_ticket->timestamp());
    CHECK_EQUAL(2, m_ticket->low());
    CHECK_EQUAL(3, m_ticket->high());
    CHECK_EQUAL(4, m_ticket->last());
    CHECK_EQUAL(5, m_ticket->bid());
    CHECK_EQUAL(6, m_ticket->ask());
    CHECK_EQUAL(7, m_ticket->volume());
    CHECK_EQUAL(8, m_ticket->source());
}
