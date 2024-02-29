//
// Created by gzhuadmin on 23-5-16.
//

#include "io/torch_api.hpp"

#include <utility>

inline char const* labels[8] = {
  "benign",
  "ddos",
  "dos",
  "ftp-patator",
  "infiltration",
  "port-scan",
  "ssh-patator",
  "web-attack"
};

TorchAPI::TorchAPI(std::string model_path) : m_model_path(std::move(model_path)) {}

std::string TorchAPI::predict(std::vector<torch::jit::IValue> const& inputs) const {
  const torch::Device device(torch::kCPU);
  torch::jit::script::Module model = torch::jit::load(this->m_model_path);
  model.to(device);
  const at::Tensor output = model.forward(inputs).toTensor();
  const auto index = argmax(output, 1).item<long>();
  return labels[index];
}
