//
//  ViewController.m
//  Example
//
//  Created by YoloMao on 2021/3/30.
//

#import "ViewController.h"
#import <NodeMediaClient/NodeMediaClient.h>
//#import <IJKMediaFrameworkWithSSL/IJKMediaFrameworkWithSSL.h>

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UIView *playerView;

@property (nonatomic, strong) NodePlayer *node;
//@property (nonatomic, strong) IJKFFMoviePlayerController *player;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //NodeMediaClient
    NodePlayer *node = [[NodePlayer alloc] init];
    node.playerView = self.playerView;
    node.inputUrl = @"rtmp://ns8.indexforce.com/home/mystream";
    self.node = node;

    //IJKPlayer
//    self.player = [[IJKFFMoviePlayerController alloc] initWithContentURLString:@"rtmp://58.200.131.2:1935/livetv/gdtv" withOptions:nil];
//    self.player.view.frame = self.playerView.bounds;
//    [self.playerView addSubview:self.player.view];
//    [self.player prepareToPlay];
}

- (IBAction)playAction:(UIButton *)sender {
    [self.node start];
    
//    [self.player play];
}

@end
