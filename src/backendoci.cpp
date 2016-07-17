#include "backendoci.h"

BackendOCI::BackendOCI(QString tempFileName, int ociID)
{
    m_tempFileName = tempFileName;
    m_ociID = ociID;
}

bool BackendOCI::exists(const QString& repoUrl)
{
    return ZypperUtils::exists( repoUrl.toStdString() );
}

void BackendOCI::callBackendHelper()
{
    m_process = new QProcess;
    
    QString command("xdg-su -u root -c \"/usr/sbin/oneclickhelper ");
    command.append( QString::number( m_ociID ) );
    command.append( "\"" );
    qDebug() << command;
    
    m_process->start( command );
    emit checkForConflicts();	// Gui while OCIhelper checks for conflicts
}
