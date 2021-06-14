#include <gmock/gmock.h>
#include <gtest/gtest.h>

struct Turtle
{
    int i_;
    virtual ~Turtle() =default;
    virtual int get_value() const =0;
    virtual int set_value(int i) =0;
};

struct MockTurtle: public Turtle
{
    MOCK_METHOD(int, get_value, (), (const, override));
    MOCK_METHOD(int, set_value, (int i), (override));
};

TEST(TestTurtle, TestMockSeq)
{
    MockTurtle mockT{};
    {
        testing::InSequence seq{};

        EXPECT_CALL(mockT, set_value(0))
            .WillOnce(testing::Return(10))
            .WillOnce(testing::Return(20));

        EXPECT_CALL(mockT, set_value(1))
            .WillOnce(testing::Return(11))
            .WillOnce(testing::Return(12));
    }

    EXPECT_EQ(mockT.set_value(0), 10);
    EXPECT_EQ(mockT.set_value(0), 20);
    EXPECT_EQ(mockT.set_value(1), 11);
    EXPECT_EQ(mockT.set_value(1), 12);
}
