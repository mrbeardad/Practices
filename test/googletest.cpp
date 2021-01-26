#include <gmock/gmock.h>
#include <gtest/gtest.h>

struct A
{
    virtual ~A() {};
    virtual double get_value(int i) const =0;
};

struct MockA: public A
{
    MOCK_METHOD(double, get_value, (int i), (const, override));
};

TEST(TestA, TestMockSeq)
{
    MockA ma{};
    {
    testing::InSequence seq{};
    EXPECT_CALL(ma, get_value(0))
        .WillOnce(testing::Return(0.0))
        .RetiresOnSaturation();
    EXPECT_CALL(ma, get_value)
        .WillOnce(testing::Return(1.0))
        .RetiresOnSaturation();
    }
    EXPECT_EQ(ma.get_value(1), 0);
    EXPECT_EQ(ma.get_value(1), 1);
}

TEST(FooDeathTest, Demo)
{
    int* p2i{};
    // EXPECT_DEATH(*p2i, "seg");
    EXPECT_EXIT(*p2i = 1, testing::KilledBySignal(SIGSEGV), "");
}
