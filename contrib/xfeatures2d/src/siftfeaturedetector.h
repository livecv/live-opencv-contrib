#ifndef SIFT_H
#define SIFT_H

#include <QQuickItem>
#include "qfeaturedetector.h"

namespace lv{

class SIFTFeatureDetector : public QFeatureDetector{

    Q_OBJECT

public:
    SIFTFeatureDetector(QQuickItem* parent = 0);
    ~SIFTFeatureDetector();

    void initialize(const QVariantMap& settings) Q_DECL_OVERRIDE;

public slots:
    void licenseAccepted(const QString& id);

protected:
    virtual void detect() Q_DECL_OVERRIDE;
    virtual void componentComplete() Q_DECL_OVERRIDE;

private:
    bool m_licenseAccepted;
};

}// namespace

#endif // SIFT_H
