//
//  LISRootViewController.h
//  UKCourses
//
//  Created by Criss Myers on 21/05/2012.
//  Copyright (c) 2012 UCLan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LISRootPickerViewController.h"
#import "LISResultsViewController.h"
#import "LISMasterViewController.h"

@class LISAppSetup;
@class LISXMLParser;

@interface LISRootViewController : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate, PickerDelegate, TableDelegate, TableiPadDelegate> {
    
    BOOL secondary;
    BOOL secondaryiPad;
}

@property (strong, nonatomic) LISAppSetup *initalSetup;
@property (strong, nonatomic) LISXMLParser *xmlParser;

@property (strong, nonatomic) LISResultsViewController *resultsView;
@property (strong, nonatomic) LISRootPickerViewController *accessPicker;
@property (strong, nonatomic) LISMasterViewController *ipadResults;

@property (strong, nonatomic) IBOutlet UITextField *keywords;
@property (strong, nonatomic) IBOutlet UITextField *postcode;

@property (strong, nonatomic) IBOutlet UIPickerView *picker;
@property (strong, nonatomic) IBOutlet UIView *pickerControllerView;

@property (strong, nonatomic) IBOutlet UIView *topView;
@property (strong, nonatomic) IBOutlet UIView *bottomView;
@property (strong, nonatomic) IBOutlet UIView *grewView;

@property (strong, nonatomic) IBOutlet UIButton *institutions;
@property (strong, nonatomic) IBOutlet UIButton *qualifications;
@property (strong, nonatomic) IBOutlet UIButton *studymodes;
@property (strong, nonatomic) IBOutlet UIButton *searchdistance;
@property (strong, nonatomic) IBOutlet UIButton *displayorder;
@property (strong, nonatomic) IBOutlet UIButton *units;

@property (strong, nonatomic) IBOutlet UIButton *advanced;
@property (strong, nonatomic) IBOutlet UIView *aboutView;
@property (strong, nonatomic) IBOutlet UIView *accessabilityView;

@property NSInteger pickerNumber;

@property (strong, nonatomic) UITapGestureRecognizer *tapRecognizer;
@property (strong, nonatomic) UITapGestureRecognizer *hidePicker;

@property (strong,nonatomic) NSString *docsDirectory;

@property (strong,nonatomic) NSMutableArray *providerArray;
@property (strong,nonatomic) NSMutableArray *qualificationsArray;
@property (strong,nonatomic) NSMutableArray *studymodesArray;
@property (strong,nonatomic) NSMutableArray *searchdistanceArray;
@property (strong,nonatomic) NSMutableArray *displayorderArray;
@property (strong,nonatomic) NSMutableArray *unitsArray;

@property (strong, nonatomic) NSString *providerString;
@property (strong, nonatomic) NSString *courseString;
@property (strong, nonatomic) NSString *qualString;
@property (strong, nonatomic) NSString *studyString;
@property (strong, nonatomic) NSString *distString;
@property (strong, nonatomic) NSString *unitString;
@property (strong, nonatomic) NSString *orderString;
@property (strong, nonatomic) NSString *locationString;
@property (strong, nonatomic) IBOutlet UIView *alertView;

@property (strong, nonatomic) IBOutlet UILabel *loadingMsg;

@property (strong, nonatomic) NSString *totalHits;
@property (strong, nonatomic) NSString *urlPath;

- (IBAction)searchData:(id)sender;
- (IBAction)loadAdvanced:(id)sender;
- (IBAction)basic:(id)sender;

- (IBAction)uclanWeb:(id)sender;

- (IBAction)institutionsSet:(id)sender;
- (IBAction)qualificationSet:(id)sender;
- (IBAction)studymodesSet:(id)sender;
- (IBAction)searchdistanceSet:(id)sender;
- (IBAction)displayorderSet:(id)sender;
- (IBAction)unitsSet:(id)sender;

- (IBAction)loadInfo:(id)sender;
- (IBAction)switchBack:(id)sender;

-(void)pickerReply:(NSInteger)pickNumber:(NSString *)pickerString:(NSString *)pickerName;
-(void)loadMoreResults:(NSString *)path;

- (void)setupArrays;
- (void)response;
- (void)totalResults:(NSString *)hits;

@end
