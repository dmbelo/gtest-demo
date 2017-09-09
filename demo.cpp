#include <iostream>
#include <gtest/gtest.h>

class BankAccount
{

public:

    int balance = 0;

    BankAccount()
    {

    }

    explicit BankAccount(const int balance) : balance{balance}
    {

    }

    void deposit(int amount)
    {
        balance += amount;
    }

    int withdraw(int amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            return 1;
        }
        return 0;
    }

};

struct BankAccountTest : testing::Test
{

    BankAccount* account;

    BankAccountTest()
    {
        account = new BankAccount;
    }

    virtual ~BankAccountTest()
    {
        delete account;
    }
};

TEST_F(BankAccountTest, BankAccountStartsEmpty)
{
    EXPECT_EQ(0, account->balance);
}

TEST_F(BankAccountTest, CanDepositMoney)
{
    account->deposit(100);
    EXPECT_EQ(100, account->balance);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}