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
#import "../../Common/RandomMock.h"

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
    FieldModel* field = new FieldModel(640, 480, 3, 32, -10, 10, new RandomMock());
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
    field->update(0.1f);
    XCTAssertEqual(1, (int)field->getBalls().size());
}

- (void)testBallMove
{
    FieldModel* field = new FieldModel(640, 480, 3, 32, -10, 10, new RandomMock());
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
    FieldModel* field = new FieldModel(640, 480, 3, 32, -513, 10, new RandomMock());
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(3);
    XCTAssertTrue(listener->createdBall);
    BallModel* ball = listener->createdBall;
    BallListenerMock* ballListener = new BallListenerMock();
    ball->addListener(ballListener);
    XCTAssertFalse(ballListener->deleteCalled);
    XCTAssertEqual(1, (int)field->getBalls().size());
    field->update(1);
    XCTAssertTrue(ballListener->deleteCalled);
    XCTAssertEqual(0, (int)field->getBalls().size());
}

- (void)testBallTouch
{
    FieldModel* field = new FieldModel(640, 480, 3, 32, -513, 10, new RandomMock());
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(3);
    XCTAssertTrue(listener->createdBall);
    BallModel* ball = listener->createdBall;
    BallListenerMock* ballListener = new BallListenerMock();
    ball->addListener(ballListener);
    XCTAssertFalse(ballListener->deleteCalled);
    XCTAssertEqual(1, (int)field->getBalls().size());
    field->touch(ball->getX(), ball->getY());
    XCTAssertTrue(ballListener->deleteCalled);
    XCTAssertEqual(0, (int)field->getBalls().size());
}

- (void)testRestTimeUpdate
{
    FieldModel* field = new FieldModel(640, 480, 3, 32, -513, 10, new RandomMock());
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(3);
    XCTAssertEqual(0.7f, listener->percent);
}

- (void)testScore
{
    // {pos, color, ...}
    IRandom* rnd = new RandomMock({0, 0, 0, 1, 0, 2});
    FieldModel* field = new FieldModel(640, 480, 1, 32, -32, 1000, rnd);
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(1); // spawn red ball
    field->update(1); // spawn green ball
    field->update(1); // spawn blue ball
    field->update(1); // push all ball in field
    XCTAssertEqual(4, (int)field->getBalls().size());
    XCTAssertEqual(16.0f, field->getBalls()[0]->getX());
    XCTAssertEqual(400.0f, field->getBalls()[0]->getY());
    field->touch(16, 400);
    XCTAssertEqual(3, (int)field->getBalls().size());
    XCTAssertEqual(1, listener->score);
    field->touch(16, 432);
    XCTAssertEqual(2, (int)field->getBalls().size());
    XCTAssertEqual(2, listener->score);
    field->touch(16, 464);
    XCTAssertEqual(1, (int)field->getBalls().size());
    XCTAssertEqual(3, listener->score);
}

- (void)testNotScored
{
    // {pos, color, ...}
    IRandom* rnd = new RandomMock({0, 0, 0, 1, 0, 1});
    FieldModel* field = new FieldModel(640, 480, 1, 32, -32, 1000, rnd);
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(1); // spawn red ball
    field->update(1); // spawn green ball
    field->update(1); // spawn green ball again
    field->update(1); // push all ball in field
    XCTAssertEqual(4, (int)field->getBalls().size());
    field->touch(16, 400);
    XCTAssertEqual(3, (int)field->getBalls().size());
    XCTAssertEqual(1, listener->score);
    field->touch(16, 432);
    XCTAssertEqual(2, (int)field->getBalls().size());
    XCTAssertEqual(2, listener->score);
    field->touch(16, 464);
    // cant get score for invalid color touch
    XCTAssertEqual(2, (int)field->getBalls().size());
    XCTAssertEqual(2, listener->score);
}

@end
