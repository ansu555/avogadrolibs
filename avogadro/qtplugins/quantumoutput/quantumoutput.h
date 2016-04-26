#ifndef AVOGADRO_QTPLUGINS_QUANTUMOUTPUT_H
#define AVOGADRO_QTPLUGINS_QUANTUMOUTPUT_H

#include <avogadro/qtgui/extensionplugin.h>

class QAction;
class QDialog;
class QProgressDialog;

namespace Avogadro {

namespace QtGui {
class MeshGenerator;
}
namespace Core {
class BasisSet;
class Cube;
class Mesh;
}

namespace QtPlugins {

class GaussianSetConcurrent;
class SlaterSetConcurrent;
class SurfaceDialog;

class QuantumOutput : public QtGui::ExtensionPlugin
{
  Q_OBJECT

public:
  explicit QuantumOutput(QObject *parent = 0);
  ~QuantumOutput();

  QString name() const { return tr("Quantum output"); }

  QString description() const { return tr("Read output from quantum codes."); }

  QList<QAction *> actions() const;

  QStringList menuPath(QAction *) const;

  void setMolecule(QtGui::Molecule *mol);

private slots:
  void surfacesActivated();
  void calculateSurface(int index, float isosurfaceValue,
                        float resolutionStepSize);
  void displayCube();
  void meshFinished();

private:
  QList<QAction *>    m_actions;
  QProgressDialog    *m_progressDialog;

  QtGui::Molecule    *m_molecule;
  Core::BasisSet     *m_basis;

  GaussianSetConcurrent *m_concurrent;
  SlaterSetConcurrent *m_concurrent2;

  Core::Cube        *m_cube;
  std::vector<Core::Cube *>        m_cubes;
  Core::Mesh        *m_mesh1;
  Core::Mesh        *m_mesh2;
  QtGui::MeshGenerator *m_meshGenerator1;
  QtGui::MeshGenerator *m_meshGenerator2;

  float m_isoValue;

  SurfaceDialog *m_dialog;
};

}
}

#endif // AVOGADRO_QTPLUGINS_QUANTUMOUTPUT_H
