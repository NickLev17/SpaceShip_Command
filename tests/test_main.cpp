#include <iostream>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <math.h>
#include <stdexcept>
#include "../include/Interfaces/IMovingObject.h"
#include "../include/Interfaces/IRotatingObject.h"
#include "../include/Interfaces/IFuelObject.h"
#include "../include/Interfaces/IMovingObject.h"
#include "../include/Interfaces/IRotatingObject.h"
#include "../include/Interfaces/IBurnFuelObject.h"
#include "../include/Commands/MoveCommand.h"
#include "../include/Commands/RotateCommand.h"
#include "../include/Commands/CheckFuelCommand.h"
#include "../include/Commands/BurnFuelCommand.h"
#include "../include/SpaceShip.h"
#include "../include/Commands/MacroCommand.h"
#include<gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::_;
using namespace testing;
using namespace std;

class MockBurnFuelObject : public IBurnFuelObject 
{
public:
MOCK_CONST_METHOD0(getFuel, double());
MOCK_METHOD1(setFuel, void(double));
};

class MockFuelObject : public IFuelObject 
{
public:
    MOCK_CONST_METHOD0(getFuel, double());
    MOCK_CONST_METHOD0(getStepFuel, double());
    MOCK_METHOD1(setFuel, void(double));
    MOCK_METHOD1(setStepFuel, void(double));
};

TEST(BurnFuelTest, GetAndSetFuelSequence) 
{
MockBurnFuelObject mock;

EXPECT_CALL(mock, getFuel())
.WillOnce(testing::Return(10.0))
.WillRepeatedly(testing::Return(7.5));

EXPECT_CALL(mock, setFuel(testing::DoubleEq(7.5)));

EXPECT_DOUBLE_EQ(mock.getFuel(), 10.0);

mock.setFuel(7.5);

EXPECT_DOUBLE_EQ(mock.getFuel(), 7.5);
}

TEST(FuelObjectTest, StepFuelBehavior) 
{
MockFuelObject mock;

EXPECT_CALL(mock, getFuel())
.WillOnce(testing::Return(5.0))
.WillRepeatedly(testing::Return(4.5));

EXPECT_CALL(mock, getStepFuel())
.WillOnce(testing::Return(0.5))
.WillRepeatedly(testing::Return(0.5));

EXPECT_CALL(mock, setStepFuel(testing::DoubleEq(0.5)));
EXPECT_CALL(mock, setFuel(testing::DoubleEq(4.5)));

EXPECT_DOUBLE_EQ(mock.getFuel(), 5.0);

mock.setStepFuel(0.5);

mock.setFuel(4.5);

EXPECT_DOUBLE_EQ(mock.getStepFuel(), 0.5);
EXPECT_DOUBLE_EQ(mock.getFuel(), 4.5);
}

TEST(CheckFuelCommandTest, ConstructorReadsFuel)
{
    MockFuelObject obj;
    EXPECT_CALL(obj, getFuel())
        .WillOnce(Return(10.0));

    CheckFuelCommand cmd(obj);
}


TEST(CheckFuelCommandTest, ExecuteThrowsWhenFuelIsNotEnough)
{
    MockFuelObject obj;

    EXPECT_CALL(obj, getFuel())
        .WillOnce(Return(1.0))
        .WillOnce(Return(1.0));

    EXPECT_CALL(obj, getStepFuel())
        .WillOnce(Return(2.5));

    CheckFuelCommand cmd(obj);
    EXPECT_THROW(cmd.execute(), const char*);
}

class MockCommand : public ICommand 
{
public:

    MOCK_METHOD(void, execute, (), (override));
};


TEST(MacroCommandTest, ExecuteWithNoCommandsDoesNotThrow) 
{
    std::vector<std::unique_ptr<ICommand>> emptyCommands;

    MacroCommand cmd(std::move(emptyCommands));

    EXPECT_NO_THROW(cmd.execute());
}

TEST(MacroCommandTest, ExecuteCallsExecuteOnSingleCommand) 
{
    std::vector<std::unique_ptr<ICommand>> commands;
    commands.reserve(1); 
    commands.push_back(std::make_unique<MockCommand>());

    EXPECT_CALL(static_cast<MockCommand&>(*commands[0]), execute()).Times(1);

    MacroCommand cmd(std::move(commands));
    cmd.execute();
}

TEST(MacroCommandTest, ExecuteCallsExecuteOnAllCommandsInSequence) 
{
    std::vector<std::unique_ptr<ICommand>> commands;
    commands.reserve(3);
    commands.push_back(std::make_unique<MockCommand>());
    commands.push_back(std::make_unique<MockCommand>());
    commands.push_back(std::make_unique<MockCommand>());

    ::testing::InSequence s;

    EXPECT_CALL(static_cast<MockCommand&>(*commands[0]), execute()).Times(1);
    EXPECT_CALL(static_cast<MockCommand&>(*commands[1]), execute()).Times(1);
    EXPECT_CALL(static_cast<MockCommand&>(*commands[2]), execute()).Times(1);

    MacroCommand cmd(std::move(commands));
    cmd.execute();
}


int main(int argc, char **argv) {
::testing::InitGoogleMock(&argc, argv);
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}

