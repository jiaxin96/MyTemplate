
	int max_val(int pb) {
		int alpha = -INF;
		int beta = pb;

		if (deep == 0) {
			return eval();
		}

		int [] step = new int[2]{startpos, endpos};

		int t;

		for (int i : step) {


			t = min_val();

			if (t > alpha) {
				alpha = t;
			}


			if (alpha >= beta) {
				break;
			}

		}


		alpha = t;

		return alpha;

	}


	int min_val(int pa) {
		int beta = INF;
		int alpha = pa;

		if (deep == 0) {
			return eval();
		}

		int [] step = new int[2]{startpos, endpos};

		int t;

		for (int i : step) {


			t = max_val();

			if (t < beta) {
				beta = t;
			}


			if (alpha >= beta) {
				break;
			}

		}


		beta = t;

		return beta;

	}