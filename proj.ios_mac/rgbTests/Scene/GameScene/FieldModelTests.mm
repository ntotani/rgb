//
//  FieldModelTests.m
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#import <XCTest/XCTest.h>
#import "FieldModel.h"
#import "FieldListenerMock.h"
#import "BallListenerMock.h"

@interface FieldModelTests : XCTestCase

@end

@implementation FieldModelTests

- (void)setUp
{
    [super setUp];
    // Put setup code here; it will be run once, before the first test case.
}

- (void)tearDown
{
    // Put teardown code here; it will be run once, after the last test case.
    [super tearDown];
}

- (void)testBallCreate
{
    FieldModel* field = new FieldModel(640, 480, 3, 32, -10);
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(1);
    XCTAssertEqual(0, (int)field->getBalls().size());
    XCTAssertFalse(listener->called);
    XCTAssertFalse(listener->createdBall);
    field->update(2);
    XCTAssertEqual(1, (int)field->getBalls().size());
    XCTAssertTrue(listener->called);
    XCTAssertTrue(listener->createdBall);
}

- (void)testBallMove
{
    FieldModel* field = new FieldModel(640, 480, 3, 32, -10);
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(3);
    XCTAssertTrue(listener->createdBall);
    BallModel* ball = listener->createdBall;
    BallListenerMock* ballListener = new BallListenerMock();
    ball->addListener(ballListener);
    float prevY = ball->getY();
    field->update(1);
    XCTAssertTrue(ballListener->called);
    XCTAssertNotEqual(prevY, ball->getY());
}

- (void)testBallDelete
{
    FieldModel* field = new FieldModel(640, 480, 3, 32, -10);
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(3);
    XCTAssertTrue(listener->createdBall);
    BallModel* ball = listener->createdBall;
    BallListenerMock* ballListener = new BallListenerMock();
    ball->addListener(ballListener);
    XCTAssertFalse(ballListener->deleteCalled);
    XCTAssertEqual(1, (int)field->getBalls().size());
    field->update(49);
    XCTAssertTrue(ballListener->deleteCalled);
    XCTAssertEqual(0, (int)field->getBalls().size());
}

@end
