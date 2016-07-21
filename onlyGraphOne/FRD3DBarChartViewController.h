#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>


@class FRD3DBarChartViewController;

@protocol FRD3DBarChartViewControllerDelegate <NSObject>

@required

// number of rows to display in the chart.
-(int) frd3DBarChartViewControllerNumberRows:(FRD3DBarChartViewController *) frd3DBarChartViewController;
// number of columns to display in the chart
-(int) frd3DBarChartViewControllerNumberColumns:(FRD3DBarChartViewController *) frd3DBarChartViewController;
// maximum value (height of the bar). Heights are normalized using this value.
-(float) frd3DBarChartViewControllerMaxValue:(FRD3DBarChartViewController *) frd3DBarChartViewController;
// value (height) of a bar in the chart
-(float) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController valueForBarAtRow:(int)row column:(int)column;


@optional

// indicates if there is a bar on a row/column. Return false here is different that returning false on
// frd3DBarChartViewController:valueForBarAtRow:column, the latter will render acolored square
// with no height, the former will result in an empty cell on the grid.
-(bool) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController hasBarForRow:(int)row column:(int) column;
// strings to be displayed on the left side of the grid. Return nil to skip the legend for a row.
-(NSString *) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController legendForRow:(int) row;
// strings to be displayed on the front side of the grid. Return nil to skip the legend for a column.
-(NSString *) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController legendForColumn:(int) column;
// strings to be displayed on the frobackground side of the chart, next to the height lines.
-(NSString *) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController legendForValueLine:(int) line;

// color of the bars.
-(UIColor *) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController colorForBarAtRow:(int)row column:(int) column ;
// the size of the bar as a percentage of the square in the grid. Return 1.0 to make the bar occupy the whole square.
// best-looking results will be obtained by returning values between 0.8 and 1.0.
-(float) frd3DBarChartViewController:(FRD3DBarChartViewController *) frd3DBarChartViewController percentSizeForBarAtRow:(int) row column:(int) column;

// enabled text label on top of the bars.
-(BOOL) frd3DBarChartViewControllerHasTopText:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// optional text to put on top of the bar
-(NSString *) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController topTextForBarAtRow:(int)row column:(int) column;
// optional font for the  text on top of the bar (default is Helvetica)
-(NSString *) frd3DBarChartViewControllerTopTextFontName:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// optional text color for the top bar text (default is white)
-(UIColor *) frd3DBarChartViewController:(FRD3DBarChartViewController *)frd3DBarChartViewController colorForTopTextBarAtRow:(int)row column:(int) column;


// the font name to use in the row chart legend. 
-(NSString *) frd3DBarChartViewControllerRowLegendFontName:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// the font name to use in the column chart legend. 
-(NSString *) frd3DBarChartViewControllerColumnLegendFontName:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// font name to be used in the height values in background pane
-(NSString *) frd3DBarChartViewControllerValueLegendFontName:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// the color to use in the row chart legend (default white)
-(UIColor *) frd3DBarChartViewControllerRowLegendColor:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// the color to use in the column chart legend. (default is white)
-(UIColor *) frd3DBarChartViewControllerColumnLegendColor:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// the color to use for the height value labels in the background pane.
-(UIColor *) frd3DBarChartViewControllerValueLegendColor:(FRD3DBarChartViewController *)frd3DBarChartViewController;
// the number of lines to dsplay in the background grid plane.
-(int) frd3DBarChartViewControllerNumberHeightLines:(FRD3DBarChartViewController *)frd3DBarChartViewController;

@end

enum
{
    kUpdateChartOptionsDoNotUpdateRowLegend         = 1 <<  0,
    kUpdateChartOptionsDoNotUpdateColumnLegend      = 1 <<  1,
    kUpdateChartOptionsDoNotUpdateValueLegend       = 1 <<  2,
    kUpdateChartOptionsDoNotUpdateLegends           = 7,
} ;
typedef NSUInteger kUpdateChartOptions;

/** the main 3D bar chart controller class.
 */
@interface FRD3DBarChartViewController : GLKViewController

@property (nonatomic, strong) id<FRD3DBarChartViewControllerDelegate> frd3dBarChartDelegate;
@property (nonatomic) BOOL useCylinders;

/**
 * Trigger an update of the chart. Chart elements that are updated by default
 * are the bar columns, the bar colors, the horizontal bars and the chart label textures...
 * Use the option parameter to control wether the label texture should be regenerated or not.
 * There is a performance hit in regenerating label texture, it is recommended to only generate them
 * if the label text has changed...
 *
 * @param animated YES to animate the chart update.
 * @param duration animation duration in second.
 * @param options update options. Current options allow you to prevent label textures to be regenerated.
 */
-(void) updateChartAnimated:(BOOL) animated animationDuration:(NSTimeInterval)duration options:(kUpdateChartOptions)options;

@end
