#include "FacadeModel.h"

namespace s21 {

FacadeModel::FacadeModel() {
  object_model_ = new ObjectModel;
  parser_model_ = new ParserModel;
  affine_model_ = new AffineModel;
}

FacadeModel::~FacadeModel() {
  delete object_model_;
  delete parser_model_;
  delete affine_model_;
}

int FacadeModel::get_facets_count() const noexcept {
  return object_model_->get_facets_count();
}

int FacadeModel::get_points_count() const noexcept {
  return object_model_->get_points_count();
}

void FacadeModel::add_points_movement(const std::string &x,
                                      const std::string &y,
                                      const std::string &z) const noexcept {
  affine_model_->add_points_movement(x, y, z);
}

void FacadeModel::add_points_scaling(const std::string &x, const std::string &y,
                                     const std::string &z) const {
  affine_model_->add_points_scaling(x, y, z);
}

void FacadeModel::add_points_rotation(const std::string &angle,
                                      const std::string &type) const {
  affine_model_->add_points_rotation(angle, type);
}

void FacadeModel::execute_changes() const {
  affine_model_->execute_changes(object_model_);
}

void FacadeModel::read_from_file(const std::string &filename) const {
  parser_model_->read_from_file(object_model_, filename);
}

std::string FacadeModel::get_file_basename(const std::string &filename) const {
  return parser_model_->get_file_basename(filename);
}

void FacadeModel::generate_data(const std::string &filename) const {
  GnuPlotSingleton::get_instance().generate_data(object_model_, filename);
}

void FacadeModel::call_gnuplot(int width, int height) const {
  GnuPlotSingleton::get_instance().call_gnuplot(width, height);
}

}  // namespace s21
