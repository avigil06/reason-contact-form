type rules('a) =
  | NotEmpty;

let validate = (rule, value) =>
  switch (rule) {
  | NotEmpty => String.length(value) > 0
  };

let getError = (rule, field) =>
  switch (rule) {
  | NotEmpty => field ++ " is required"
  };
