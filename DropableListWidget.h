#include <QListWidget>
#include <QWidgetItem>
#include <QPoint>

// https://www.jianshu.com/p/8fedc14b3ea8
// https://www.cnblogs.com/findumars/p/5599427.html

// Dropable QListWidget
class DropableListWidget : public QListWidget
{
	Q_OBJECT

signals:
	void dragEnterEvent(QDragEnterEvent *event) override;
	void dragMoveEvent(QDragMoveEvent *event) override;
	void dropEvent(QDropEvent *event) override;

public:
	DropableListWidget(QWidget *parent);
	~DropableListWidget() {}
};